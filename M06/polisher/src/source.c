#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "source.h"

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments. It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char* delete_comments(char* input) {

    int input_len = strlen(input);
    char* output = (char*) malloc(input_len + 1);
    int output_index = 0;
    int comment_block = 0;

    for (int i = 0; i < input_len; i++) {
        if (!comment_block) {
            if (input[i] == '/' && i + 1 < input_len && input[i+1] == '*') {

                comment_block = 1;
                i++;
            } 
            else if (input[i] == '/' && i + 1 < input_len && input[i+1] == '/') {
                while (i < input_len && input[i] != '\n') {

                    i++;
                }
            } else {

                output[output_index] = input[i];
                output_index++;
            }
        } else {
            if (input[i] == '*' && i + 1 < input_len && input[i+1] == '/') {

                comment_block = 0;
                i++;
            }
        }
    }
    
    output[output_index] = '\0';
    
    if (input != output) {
        free(input);
    }
    
    return output;
}