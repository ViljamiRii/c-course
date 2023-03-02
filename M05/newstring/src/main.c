#include "source.c"
#include <stdio.h>

int main()
{
    /* Implement your own tests here. Free feel to modify. */

    char str[] = "Hello student?candidateJack";

    // Test print
    qstr_print(str);

    // Testing length
    printf("\nlength: %d\n", qstr_length(str));

    // test cat
    char buf[80] = "John?student";
    int ret = qstr_cat(str, buf);
    printf("After cat: '");
    qstr_print(buf);
    printf("' (ret: %d)\n", ret);

    return 0;
}
