#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"

/**
 * \brief Writes the products in the shop into the specified binary file. 
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_binary(const char* filename, const Product* shop) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        return 1;
    }

    size_t num_products = 0;
    while (shop[num_products].name[0] != '\0') {
        fwrite(&shop[num_products], sizeof(Product), 1, f);
        num_products++;
    }

    fclose(f);
    return 0;
}

/**
 * \brief Reads the shop products from the specified binary file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 */
Product* read_binary(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);
    int count = size / sizeof(Product);
    Product* shop = (Product*) malloc(sizeof(Product) * (count+1));
    fread(shop, sizeof(Product), count, f);
    fclose(f);
    shop[count].name[0] = '\0';
    return shop;
}

/**
 * \brief  Writes the shop products into a text file.
 * 
 * \details The file writes each product as follows.
 * 
 *          <product-name> <price> <in-stock>
 * 
 *       In other words, the structure fields are separated with a space, and the array 
 *       elements are separated by a newline. Because the data items are separated by a 
 *       space, the product name should not have spaces in it.
 * 
 *       The last array element (with the name of null character) should not be 
 *       written into the file.
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_plaintext(const char* filename, const Product* shop) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        return 1;
    }
    int i = 0;
    while (shop[i].name[0] != '\0') {
        fprintf(f, "%s %.6f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
        i++;
    }
    fclose(f);
    return 0;
}

/**
 * \brief Reads the shop products from the specified text file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 *
 * \note You can parse each line using sscanf function.
 */

Product* read_plaintext(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }
    Product* shop = (Product*) malloc(sizeof(Product) * 100);
    int count = 0;
    while (fscanf(f, "%30s %f %d", shop[count].name, &shop[count].price, &shop[count].in_stock) == 3) {
        count++;
    }
    fclose(f);
    shop[count].name[0] = '\0';
    return shop;
}