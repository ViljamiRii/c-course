#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myprint(const char *str, ...) {
    va_list args;
    va_start(args, str);

    int count = 0;
    const char *format_specifier = strchr(str, '&');
    while (format_specifier != NULL) {

        fwrite(str, 1, format_specifier - str, stdout);

        int arg = va_arg(args, int);
        printf("%d", arg);

        count++;
        str = format_specifier + 1;
        format_specifier = strchr(str, '&');
    }

    fwrite(str, 1, strlen(str), stdout);

    va_end(args);

    return count;
}