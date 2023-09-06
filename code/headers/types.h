#ifndef TYPES_H_
#define TYPES_H_

#include "all.h"

boolean type_is_native(type);

boolean type_is_custom(type);

boolean type_is_enum(type);

boolean type_is_struct(type);

boolean type_is_pointer(type);

boolean type_array_is_2d_pointer(type);

char* type_to_string(type);

output* __int_to_size(int);

output* __size_to_int(size_t);

char* get_type_format(type);

size_t get_type_size(type, boolean);

#endif
