 #ifndef __TC_CNTR_H__
#define __TC_CNTR_H__
void initTrafficCounters();
int readCounter(int);
void resetCounter(int);
int resetAllCounters(int);
#endif /* __TC_CNTR_H__ */