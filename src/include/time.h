#ifndef __TIME_H__
#define __TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long tv_sec;   // Seconds
    long tv_nsec;  // Nanoseconds
};

/* Declaration of nanosleep */
int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif /* __TIME_H__ */
