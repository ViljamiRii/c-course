#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Fetches bits from a byte array, of which bit indexes are stated in 
 *        bit_idxs array containing n elements. It returns the sum of these 
 * 		  bits.
 * 
 * \details This function fetches bits from a byte array, which contains 
 *          suitable number of bytes to cover the largest bit index in 
 *          bit_idxs array. It assumes that the bytes in the array are 
 *          composed as follows:
 *          if array = {0xA3, 0x58}, it assumes a number 
 *          0xA358 = 1010 0011 0101 1000, and assigns bit index 0 as the 
 *          left most bit. 
 *          if bit_idxs = {0, 2, 10}, and n = 3, it fetches
 * 			1010 0011 0101 1000
 * 			^ ^         ^
 *          1, 1, 0 since bit 0 is 1, bit 2 is 1, and bit 10 is 0. 
 *          Then, it sums these bit values and returns 2.
 * 
 * \param array The byte array which has suitable number of elements to cover 
 *              the largest value in bit_idxs array.
 * \param bit_idxs The array of bit indexes, which has n elements in it. 
 * \param n The number of elements in bit_idxs array.
 * \return The sum of fetched bit values.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
unsigned int fetch_bits_sum(unsigned char* array,
							unsigned int* bit_idxs,
							unsigned int n) {
	unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int byte_idx = bit_idxs[i] / 8;
        unsigned int bit_idx = bit_idxs[i] % 8;
        unsigned char byte = array[byte_idx];
        unsigned char bit_mask = 1 << (7 - bit_idx);
        sum += (byte & bit_mask) >> (7 - bit_idx);
    }
    return sum;
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
	unsigned char array1[] = {0xA3, 0x58};
    unsigned int bit_idxs1[] = {0, 2, 10};
    unsigned int n1 = 3;
    unsigned int ed1 = 2;
    unsigned int res1 = fetch_bits_sum(array1, bit_idxs1, n1);
    printf("Test 1: ed=%u, res=%u\n", ed1, res1);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
	return 0;
}
