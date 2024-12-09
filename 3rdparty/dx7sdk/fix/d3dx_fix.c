#include <stdio.h>
int __snprintf(char *buffer, size_t size, const char *fmt, ...) {
    va_list ap;
    int r;
    va_start(ap, size);
    r = vsnprintf(buffer, size, fmt, ap);
    va_end(ap);
    return r;
}
