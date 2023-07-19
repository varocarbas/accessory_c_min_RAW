#ifndef TYPES_H_
#define TYPES_H_

#include "all.h"

boolean type_is_native(type);

boolean type_is_custom(type);

boolean type_is_enum(type);

boolean type_is_struct(type);

boolean type_is_pointer(type);

char* get_type_format(type);

size_t get_type_size(type);

char* type_to_string(type);

#endif
