#include <unistd.h>  // For write()
#include <string.h>  // For strlen()
#include <errno.h>   // For setting errno

int puts(const char *s) {
	write(1, s, strlen(s));
    write(1, "\n", 1);
    return 0;
}
