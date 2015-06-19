/* File: bytes.c
 * Copyright (C) da Kine Technologies (P) Ltd. - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vineet Maheshwari <vineet@dakinegroup.com>, June 2015
 * Revision History
 * Date        Ticket   Change Note
 * -----------------------------------
 * 20-Jun-2015  N/A     First Version Ready
 * 
 */

 static char binaryString[50];
char * getBinaryString(unsigned int bytes) {
    int i = 0;
    for(;i<16; i++) {
        binaryString[i*2] =  ((bytes << i)&0x8000)?'1':'0';
        binaryString[i*2+1] = ' ';
    }
    binaryString[i*2] = 0;
    return &binaryString[0];
}