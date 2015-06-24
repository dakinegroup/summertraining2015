/* File: tc_cli.c
 * Copyright (C) da Kine Technologies (P) Ltd. - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vineet Maheshwari <vineet@dakinegroup.com>, June 2015
 * Revision History
 * Date        Ticket   Change Note
 * -----------------------------------
 * 
 */
#include "tc_ctrl.h"
#include "tc_cli.h"
#include "mytimer.h"
#include "tc_cntr.h"

#define CMD_SET_SIZE 10
char userCommand[20];
struct {
	char* cmd;
	int (* cb)(int , char**);
} cmdHandler[CMD_SET_SIZE];

int CLI_Set(int argc, char* argsv[]);
int CLI_Go(int argc, char* argsv[]);
int CLI_ChgPo(int argc, char* argv[]);
int CLI_Get(int argc, char* argsv[]);
int CLI_Reset(int argc, char* argsv[]);

void initCli() {
	int i;
	/* initialize commands callback to zero */
	for(i=0; i < CMD_SET_SIZE; i++) {
		cmdHandler[1].cb = 0;
	}
	/* First command */
	cmdHandler[0].cmd = "set";
	cmdHandler[0].cb = CLI_Set;

	/* Second command */
	cmdHandler[1].cmd = "go";
	cmdHandler[1].cb = CLI_Go;

	/* Third command */
	cmdHandler[2].cmd = "get";
	cmdHandler[2].cb = CLI_Get;

	/* Fourth command */
	cmdHandler[3].cmd = "reset";
	cmdHandler[3].cb = CLI_Reset;

}

/*
  Developer Notes:
  parses user typed statements for retrieving commands and it's arguments
  Supported commands are:
  (checkout initCli procedure for latest)

  Commands:
    set -- sets parameters for traffic lights controller
    go  -- changes a particular pole to green
    chgPo - changes a traffic lighting sequence to preprogrammed algo.
 */
void processUserCommand() {
int i=0;
char msg[10];
char cmdFound=0,argsCount=0,*args[6],*cmd;
	/* Acknowledge to user the command typed */
  USART_Transmit_String2("Got a user command: ");
  USART_Transmit_String2(userCommand);
  USART_Transmit_String2("\r\n");
  cmd=&userCommand[0];

  /* parse and retrieve command , arguments */
  while(userCommand[i]!=0){
  	USART_Transmit_String2(msg);
  	if(userCommand[i]==' '){
         	userCommand[i++]=0;
         	argsCount++;
         	args[argsCount-1]=&userCommand[i];
  	}else i++;
   }

  sprintf(msg, "Cmd:%s:Arg(%d)\r\n", cmd, argsCount);
  USART_Transmit_String2(msg);
  for(i=0; i < CMD_SET_SIZE; i++) {
   	sprintf(msg, "Cmd:%s:(%s), %04x\r\n", cmdHandler[i].cmd, cmd, cmdHandler[i].cb);
   	USART_Transmit_String2(msg);
   	if(cmdHandler[i].cb == 0) break;
   	if(strcmp(cmdHandler[i].cmd, cmd) == 0) {
  		(*cmdHandler[i].cb)(argsCount, args);
   		break;
   	}
  }
  if(i == CMD_SET_SIZE || cmdHandler[i].cb == 0 ) {
  	USART_Transmit_String2("Invalid Command\r\n");
  }
	return 0;
}

/*
Developer Notes:
   Handler for setting variables affecting functionality of traffic lights
   argument-1# --> "it" - incoming traffic counters
   	               "thr" - 100 - 1000
   rest of the arugments depending on first parameter
   */
int CLI_Set(int argc, char* argv[]) {
int i =0, t_thr;
	USART_Transmit_String2("Cmd:Set\r\n");
	

	/* handling of first parameter */
	if(strcmp(argv[0], "it") == 0){
		if(argc < 5) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		
		incomingTraffic[0] = atoi(argv[1]);
		incomingTraffic[1] = atoi(argv[2]);
		incomingTraffic[2] = atoi(argv[3]);
		incomingTraffic[3] = atoi(argv[4]);
		USART_Transmit_String2("Changed Traffic Load\r\n");
	}

	/* handling of second parameter */
	if(strcmp(argv[0], "thr") == 0){
		if(argc < 2) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		t_thr = atoi(argv[1]);
		/*if(t_thr < 100 && t_thr > 1000) {
			USART_Transmit_String2("Must be between 100 and 1000\r\n");
			return;
		}*/
		trafficThreshold = t_thr;
		USART_Transmit_String2("Changed traffic threshold\r\n");
	}

	/* handling of second parameter */
	if(strcmp(argv[0], "pts") == 0){
		if(argc < 2) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		printTL = atoi(argv[1]);
		USART_Transmit_String2("Changed print trf status\r\n");
	}
	return 0;
}

/*
Developer Notes:
   Handler for getting variables values
   argument-1# --> "it" - incoming traffic counters
                   "thr" - threshold value
   */
int CLI_Get(int argc, char* argv[]) {
int i =0, t_thr;
char msg[30];
	USART_Transmit_String2("Cmd:Get\r\n");
	

	/* handling of first parameter */
	if(strcmp(argv[0], "it") == 0){
		if(argc < 1) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		sprintf(msg, "TrLd: %d, %d, %d, %d\r\n",incomingTraffic[0], incomingTraffic[1], \
						incomingTraffic[2],incomingTraffic[3] );
		USART_Transmit_String2(msg);		
	}

	/* handling of second parameter */
	if(strcmp(argv[0], "thr") == 0){
		if(argc < 1) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		sprintf(msg, "TrThr: %d\r\n",trafficThreshold );
		USART_Transmit_String2(msg);		
	}

	/* handling of second parameter */
	if(strcmp(argv[0], "pts") == 0){
		if(argc < 1) {
			USART_Transmit_String2("Insufficient args\r\n");
			return;
		}
		sprintf(msg, "PTS:(%04x): %d,\r\n",startingState, printTL );
		USART_Transmit_String2(msg);		
	}
	return 0;
}

/*
Developer Notes:
   Handler for making green for particular pole#n
   argument-1# --> "<pole-n>" - number of pole: 0 - 3.
   */
int CLI_Go(int argc, char* argv[]) {
int i =0;
	USART_Transmit_String2("Cmd:Go");
	for(i=0; i < argc; i++) {
		USART_Transmit_String2(argv[i]);
	}
	return 0;
	/* Change the startingState such that the pole desired has got yellow light on it */
	/* Also, it may require, any counter running there to be stopped.. advance step */
}

/*
Developer Notes:
   Handler for changing traffic light sequence / program
   argument-1# --> 0 --> type 1
                   1 --> type 2
                   etc.

   */
int CLI_ChgPo(int argc, char* argv[]) {
int i =0;
	USART_Transmit_String2("Cmd: ChgPo");
	for(i=0; i < argc; i++) {
		USART_Transmit_String2(argv[i]);
	}
	return 0;
}

int CLI_Reset(int argc, char* argv[]) {
	USART_Transmit_String2("Cmd: Reset");
	if(argc == 1) {
		if(strcmp(argv[0], "counters") == 0) {
			resetAllCounters(0);
		}
		if(strcmp(argv[0], "timers") == 0) {
			resetAllTimers(0);
		}
	}
	if(argc == 2) {
		if(strcmp(argv[0], "counter") == 0) {
			int c = atoi(argv[1]);
			resetCounter(c);
		}		
	}
	return 0;
}