#include "headers/logs.h"

char* log_to_string(const log* log_) { return (log_ != WRONG_POINTER ? log_->_message : WRONG_STRING); }

log get_new_log(void* type_error_warning_, const boolean is_error_, void* further_)
{
	log log = { type_error_warning_, is_error_, further_, get_log_message_internal(type_error_warning_, is_error_, further_) };

	return log;
}

char* get_log_message_internal(void* type_error_warning_, const boolean is_error_, void* further_)
{
	return (is_error_ ? get_error_message((type_error)type_error_warning_, further_) : get_warning_message((type_warning)type_error_warning_, further_));
}
