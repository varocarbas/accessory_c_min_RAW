#ifndef ERRORS_H_
#define ERRORS_H_

#include "all.h"

char* __get_error_message(type_error, void*);

char* error_to_string(type_error);

char* __error_to_string_full(type_error);

#endif
