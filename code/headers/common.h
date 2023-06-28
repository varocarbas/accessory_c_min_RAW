#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum { WRONG_TYPE, TYPE, ERROR, WARNING, LOG, OUTPUT, BOOLEAN, STRING, CHAR, INT, SIZE, SHORT, LONG, DOUBLE } type;
typedef enum { WRONG_ERROR, ERROR_WRONG_INPUTS } type_error;
typedef enum { WRONG_WARNING, WARNING_NOT_FOUND } type_warning;
typedef enum { FALSE, TRUE } boolean;

typedef struct log
{
	void* _type_error_warning;
	boolean _is_error;
	void* _further;
	char* _message;
}
log;

typedef struct output
{
	void* _value;
	type _type;
	boolean _is_ok;
	log _log;
}
output;

const size_t WRONG_SIZE;

char* SEPARATOR_DEFAULT;
char* SEPARATOR_PRINT_ARRAY_START;
char* SEPARATOR_PRINT_ARRAY_END;
char* SEPARATOR_PRINT_ARRAY_ITEMS;

void* WRONG_POINTER;
void* WRONG_VALUE;
char* WRONG_STRING;

const void* to_constant(void*);

void* get_wrong_value(type type_);

#endif
