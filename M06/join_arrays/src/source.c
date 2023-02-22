#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array
 * \param a2 The array 1 composed of n1 elements
 * \param n3 The number of elements in array
 * \param a3 The array 1 composed of n1 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1, const int *a1,
                 unsigned int n2, const int *a2,
                 unsigned int n3, const int *a3)
{
    int *all_elements = (int*)malloc((n1 + n2 + n3) * sizeof(int));
    if (!all_elements) return NULL;

    for (unsigned int i = 0; i < n1; i++) {
        all_elements[i] = a1[i];
    }
    for (unsigned int i = 0; i < n2; i++) {
        all_elements[n1 + i] = a2[i];
    }
    for (unsigned int i = 0; i < n3; i++) {
        all_elements[n1 + n2 + i] = a3[i];
    }

    return all_elements;
}