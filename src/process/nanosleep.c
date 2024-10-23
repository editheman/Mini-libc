#include <internal/syscall.h>
#include <stdlib.h>

int nanosleep(const struct timespec *t1, struct timespec *t2){
	return syscall(__NR_nanosleep, t1, t2);
}
