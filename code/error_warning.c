#include "headers/error_warning.h"

error_warning* __get_new_error_warning_error(const type_error error_, void* further_) { return __get_new_error_warning_internal(error_, WRONG_WARNING, TRUE, further_); }

error_warning* __get_new_error_warning_warning(const type_warning warning_, void* further_) { return __get_new_error_warning_internal(WRONG_ERROR, warning_, FALSE, further_); }

error_warning* __get_new_error_warning_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	error_warning temp = { error_, warning_, is_error_, get_error_warning_message_internal(error_, warning_, is_error_, further_) };

	error_warning* out = __assign_variable(&temp, ERROR_WARNING);

	return out;
}

char* get_error_warning_message_internal(const type_error error_, const type_warning warning_, const boolean is_error_, void* further_) { return (is_error_ ? get_error_message(error_, further_) : get_warning_message(warning_, further_)); }
