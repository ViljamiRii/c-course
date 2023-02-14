#include "source.h"
#include <stdio.h>

/**
 * \brief Calculates the sum of integer elements in an array
 *
 * \param array An array of integers
 * \param count The number elements in the array
 * \return The sum of the elements
 */
int array_sum(int *array, int count)
{
    int a = 0;
    for (int i = 0; i < count; i++) {
        a += array[i];
    }
    return a;
}
