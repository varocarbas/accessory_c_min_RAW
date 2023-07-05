#include "headers/error_warning.h"

char* error_warning_to_string(const error_warning* error_warning_) { return (error_warning_ != WRONG_POINTER ? error_warning_->_message : WRONG_STRING); }

error_warning get_new_error_warning(void* type_error_warning_, const boolean is_error_, void* further_)
{
	error_warning error_warning = { type_error_warning_, is_error_, further_, get_error_warning_message_internal(type_error_warning_, is_error_, further_) };

	return error_warning;
}

char* get_error_warning_message_internal(void* type_error_warning_, const boolean is_error_, void* further_)
{
	return (is_error_ ? get_error_message((type_error)type_error_warning_, further_) : get_warning_message((type_warning)type_error_warning_, further_));
}
