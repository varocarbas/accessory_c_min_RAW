#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

typedef enum { WRONG_TYPE0, TYPE, ERROR, WARNING, ERROR_WARNING, OUTPUT, BOOLEAN, STRING, CHAR, INT, SIZE, SHORT, LONG, DOUBLE } type;
typedef enum { WRONG_ERROR0, ERROR_WRONG_INPUTS } type_error;
typedef enum { WRONG_WARNING0, WARNING_NOT_FOUND } type_warning;
typedef enum { FALSE, TRUE } boolean;

typedef struct error_warning
{
	void* _type_error_warning;
	boolean _is_error;
	void* _further;
	char* _message;
}
error_warning;

typedef struct output
{
	void* _value;
	type _type;
	boolean _is_ok;
	error_warning _error_warning;
}
output;

const char STRING_TERMINATION;

char* SEPARATOR_DEFAULT;
char* SEPARATOR_PRINT_ARRAY_START;
char* SEPARATOR_PRINT_ARRAY_END;
char* SEPARATOR_PRINT_ARRAY_ITEMS;

error_warning* WRONG_ERROR_WARNING;
output* WRONG_OUTPUT;
char* WRONG_STRING;
void* WRONG_POINTER;

type WRONG_TYPE;
type_error WRONG_ERROR;
type_warning WRONG_WARNING;
boolean WRONG_BOOLEAN;
char WRONG_CHAR;
int WRONG_INT;
size_t WRONG_SIZE;
short WRONG_SHORT;
long WRONG_LONG;
double WRONG_DOUBLE;

#endif
