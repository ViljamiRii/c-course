#include <stdio.h>
#include <string.h>
#include "source.c"

int main()
{
    /* Count substr */
    char str2[] = "one two one twotwo three";
    printf("num_substr: %d\n", num_substr(str2, "two"));
        
    return 0;
}
