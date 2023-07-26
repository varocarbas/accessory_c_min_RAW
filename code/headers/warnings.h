#ifndef WARNINGS_H_
#define WARNINGS_H_

#include "all.h"

char* __get_warning_message(type_warning, void*);

char* warning_to_string(type_warning);

char* __warning_to_string_full(type_warning);

#endif
