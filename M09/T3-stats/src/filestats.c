#include <stdio.h>
#include <stdlib.h>
#include "filestats.h"

/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int count = 0;
    int last_char_was_newline = 1;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
            last_char_was_newline = 1;
        } else {
            last_char_was_newline = 0;
        }
    }

    if (!last_char_was_newline) {
        count++;
    }

    fclose(file);
    return count;

}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) {
	FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }

    int count = 0;
    int in_word = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v') {
            in_word = 0;
        }
    }

    if (!feof(f)) {
        return -1;
    }

    fclose(f);
    return count;
}
