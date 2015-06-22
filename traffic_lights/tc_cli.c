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

 char userCommand[30];
void processUserCommand() {
  USART_Transmit_String2("Got a user command: ");
  USART_Transmit_String2(userCommand);
  USART_Transmit_String2("\r\n");
}