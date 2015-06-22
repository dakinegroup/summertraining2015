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
 #ifndef __LIGHT_DRIVER_H__
#define __LIGHT_DRIVER_H__
#define HIGH 1
#define LOW 0
  void digitalWrite(int pin, unsigned int state);
  void shiftOutClockedData(unsigned int);

#endif /* __LIGHT_DRIVER_H__ */