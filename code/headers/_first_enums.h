#ifndef FIRST_ENUMS_H_
#define FIRST_ENUMS_H_

#include "_first_all.h"

typedef enum { WRONG_TYPE0, TYPE, ERROR, WARNING, ERROR_WARNING, OUTPUT, BOOLEAN, STRING, CHAR, INT, SIZE, SHORT, LONG, DOUBLE } type;
typedef enum { WRONG_ERROR0, ERROR_WRONG_INPUTS, ERROR_WRONG_CONVERSION } type_error;
typedef enum { WRONG_WARNING0, WARNING_NOT_FOUND } type_warning;
typedef enum { FALSE, TRUE } boolean;
typedef enum { WRONG_ACTION0, INITIALISE, ASSIGN, GET, UPDATE } action;
typedef enum { LINUX, WINDOWS } os;

#endif
