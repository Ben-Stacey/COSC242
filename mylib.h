#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
#include <stdbool.h>

/*
 * Function declarations for mylib.
 * */
extern void *emalloc(size_t s);
extern void *erealloc(void *, size_t);

#endif
