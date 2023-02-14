#include <stdio.h>

int main(void)
{
    char a = 10;
    char b = 12;
    char *d = &a;

    *d = 13;
    printf("*d: %d   d: %p   a: %d\n", *d, d, a);
    if (*d > b)
        printf("New value is greater than b!\n");
    a = 14;
    printf("d: %d\n", a);
    *d = 15;
    printf("bye bye! d is now: %d\n", *d);

    return 0;
}