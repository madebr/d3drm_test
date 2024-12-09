#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int __cdecl snprntfo(char *buffer, size_t size, const char *fmt, ...) {
    va_list ap;
    int r;
    va_start(ap, fmt);
    r = vsnprintf(buffer, size, fmt, ap);
    va_end(ap);
    return r;
}

int __cdecl sprntfo(char *buffer, const char *fmt, ...) {
    va_list ap;
    int r;
    va_start(ap, fmt);
    r = vsprintf(buffer, fmt, ap);
    va_end(ap);
    return r;
}
