#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <assert.h>
#include <ctype.h>

/**  "Safer" memory allocation for arrays
 *
 * @param s - the size we wish to memory allocate
 * @return result - void* pointer to the allocated memory
 */
void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/** resizes a block of memory that has already been 
 * allocated
 * 
 * @param p - is the value being resized
 * @param s - the size we wish to memroy allocate
 * @return result - void* pointer to the allocated memory
 */
void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
