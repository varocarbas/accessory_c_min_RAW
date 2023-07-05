#ifndef ERROR_WARNING_H_
#define ERROR_WARNING_H_

#include "all.h"

char* error_warning_to_string(const error_warning*);

error_warning get_new_error_warning(void*, boolean, void*);

char* get_error_warning_message_internal(void*, boolean, void*);

#endif
