#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Returns a comparison value obtained by comparing the names of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details The name field of a Product is a string.
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareAlpha(const void* a, const void* b) {

	const Product* product1 = (const Product*)a;
	const Product* product2 = (const Product*)b;

	return strcmp(product1->name, product2->name);
}

/**
 * \brief Returns a comparison value obtained by comparing in_stock of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details in_stock is an integer, and the products with higher stock should be
 *          placed before the products with lower stock. 
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns result of compareAlpha(a, b) if a == b
 * \returns a positive number if b should be placed before a
 */
int compareNum(const void* a, const void* b) {

	const Product* product1 = (const Product*)a;
	const Product* product2 = (const Product*)b;

	if (product1->in_stock > product2->in_stock) {
		return -1;
	}

	else if (product1->in_stock < product2->in_stock) {
		return 1;
	}

	else {
		return compareAlpha(product1, product2);
	}
}

const Product* findProduct(const Product* p_array,
						   const char* search_key,
						   int (*cmp)(const void*, const void*)) {
	size_t num_products = 0;

	while (strlen(p_array[num_products].name) != 0) {
		num_products++;
	}
	return bsearch(search_key, p_array, num_products, sizeof(Product), cmp);
}
