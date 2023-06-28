#ifndef TYPES_H_
#define TYPES_H_

#include "all.h"

boolean type_is_ok(type);

char* get_type_format(type);

size_t get_type_size(type);

char* type_to_string(type);

#endif
