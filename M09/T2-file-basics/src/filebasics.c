#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filebasics.h"


/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
    int count = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
        count++;
    }
    fclose(f);
    return count;
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char *difference(const char* file1, const char* file2) {

    const char *max_line_length_str = getenv("MAX_LINE_LENGTH");
    int max_line_length = (max_line_length_str != NULL) ? atoi(max_line_length_str) : 1000;

    FILE *f1 = fopen(file1, "r");
    if (f1 == NULL) {
        return NULL;
    }
    FILE *f2 = fopen(file2, "r");
    if (f2 == NULL) {
        fclose(f1);
        return NULL;
    }

    char line1[max_line_length];
    char line2[max_line_length];
    int line_number = 1;

    while (fgets(line1, max_line_length, f1) != NULL && 
           fgets(line2, max_line_length, f2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            size_t len = strlen(line1) + strlen(line2) + 6;
            char *result = malloc(len * sizeof(char));
            snprintf(result, len, "%s----\n%s", line1, line2);
            fclose(f1);
            fclose(f2);
            return result;
        }
        line_number++;
    }
    fclose(f1);
    fclose(f2);
    return NULL;
}