/* File: tc_main.c
 * Copyright (C) da Kine Technologies (P) Ltd. - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vineet Maheshwari <vineet@dakinegroup.com>, June 2015
 * Revision History
 * Date        Ticket   Change Note
 * -----------------------------------
 * 
 */
 #ifndef __TC_CTRL_H__
#define __TC_CTRL_H__
void initTraffiStateMachine();
int processTrafficStateMachine(int);
int checkTrafficStatus(int );
#endif /* __TC_CTRL_H__ */
