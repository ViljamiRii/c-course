#include "stringsplit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char* str, const char* split) {
	
	int count = 0;
	const char* idx = str;
	const char* element;
	size_t split_length = strlen(split);

	while ((element = strstr(idx, split)) != NULL) {
		count++;
		idx = element + split_length;
	}

	count++;
	char **elements = malloc((count + 1) * sizeof(char*));
	idx = str;
	int i = 0;

	while ((element = strstr(idx, split)) != NULL) {
		size_t length = element - idx;
		elements[i] = malloc(length + 1);
		strncpy(elements[i], idx, length);
		elements[i][length] = '\0';
		idx = element + split_length;
		i++;
	}

	size_t length = strlen(idx);
	elements[i] = malloc(length + 1);
	strcpy(elements[i], idx);
	elements[count] = NULL;
	return elements;
}

/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
	for (int i = 0; split_string[i] != NULL; i++) {
		printf("%s\n", split_string[i]);
	}
}

/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
	for (int i = 0; split_string[i] != NULL; i++) {
		free(split_string[i]);
	}
	free(split_string);
}
