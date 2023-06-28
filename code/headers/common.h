#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum { FALSE, TRUE } boolean;
typedef enum { TYPE, STRING, CHAR, INT, SIZE, SHORT, LONG, DOUBLE, BOOLEAN } type;

const short TYPE_MIN;
const short TYPE_MAX;

const size_t WRONG_SIZE;

char* SEPARATOR_PRINT_ARRAY_START;
char* SEPARATOR_PRINT_ARRAY_END;
char* SEPARATOR_PRINT_ARRAY_ITEMS;

void* WRONG_POINTER;
void* WRONG_VALUE;
char* WRONG_STRING;

const void* to_constant(void*);

void* get_wrong_value(type type_);

#endif
