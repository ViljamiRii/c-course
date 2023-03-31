#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 * \brief Compares two integers and returns their comparison result.
 * \details This function defines the order of the elements by 
 *          returning (in a stable and transitive manner): 
 *          <0	The value pointed to by 'a' goes before the value pointed to by 'b'
 *           0	The value pointed to by 'a' is equivalent to the value pointed to by 'b'
 *          >0	The value pointed to by 'a' goes after the value pointed to by 'b'
 * 
 *          In other words, this function essentially calculates the difference
 *          of the values pointed by its arguments.
 * 
 * \param a A pointer to the integer that will be compared against the 
 *          value pointed by b.
 * \param b A pointer to the integer that will be compared against the 
 *          value pointed by a.
 * \return The comparison result
 */
int compare_ints(const void* a, const void* b) {
	return *(int*) a - *(int*) b;
}

/**
 * \brief Calculates the median of the integers in an array.
 * 
 * \details This function calculates the median of an array of n integers.
 * 
 * \param array The array of n integers.
 * \param n The number of integer elements in the array. There will always be 
 *          odd number of elements. 
 * \return The median value
 * 
 * \note Median is the middle element of the array when it is sorted.
 *       
 *       stdlib.h has some useful functions that might help you to
 *       sort the array to find the median value. You might need 
 *       the comparison function compare_ints if you prefer to 
 *       use stdlib function for sorting the array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
int median(int* array, unsigned int n) {
	qsort(array, n, sizeof(int), compare_ints);
	return array[n/2];
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(void) {

	int array1[] = {3, 1, 4, 2, 5, 6};
    int median1 = median(array1, 6);
    printf("array1: %d\n", median1);

	int array2[] = {15, 20, 0, 11, 5, 8, 10, 1, 3};
    int median2 = median(array2, 9);
    printf("array2: %d\n", median2);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
	return 0;
}
