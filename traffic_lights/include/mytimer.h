#ifndef __MYTIMER_H__
#define __MYTIMER_H__

extern unsigned int timestamp[];
extern unsigned char debug_led;
typedef int (* tTimedCallBack)(int);
void initTimedTasks();
void repeat(int, tTimedCallBack);
void invokeScheduledItem();
void doOnce( int ms, tTimedCallBack);
#define USE_DEBUG_LED 0
void initTimer();
#endif /* __MYTIMER_H__ */
