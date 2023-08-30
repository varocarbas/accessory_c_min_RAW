#ifndef ERROR_WARNING_H_
#define ERROR_WARNING_H_

#include "all.h"

error_warning* __get_new_error_warning_error(type_error, void*);

error_warning* __get_new_error_warning_warning(type_warning, void*);

error_warning* __get_wrong_error_warning();

void free_error_warning(error_warning*);

error_warning* __update_error_warning(error_warning*, error_warning*);

boolean error_warning_is_ok(error_warning*);

boolean error_warnings_are_equal(error_warning*, error_warning*);

char* __error_warning_to_string(error_warning*);

error_warning* __get_new_error_warning_internal(type_error, type_warning, boolean, void*);

error_warning* __initialise_error_warning_internal(error_warning);

error_warning* __assign_error_warning_internal(error_warning*, error_warning*);

char* __get_error_warning_message_internal(type_error, type_warning, boolean, void*);

char* __get_error_warning_message_common_internal(type_error, type_warning, boolean, void*);

boolean error_warning_is_ok_internal(error_warning*, boolean);

char* __error_warning_to_string_full_internal(type_error, type_warning, boolean);

#endif
