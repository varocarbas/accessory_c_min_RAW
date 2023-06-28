#include "headers/output.h"

output get_new_output(void* value_, const type type_)
{
	output output = { value_, type_, TRUE };

	if (type_is_ok(type_) == FALSE) output = *update_output_log(&output, (void*)ERROR_WRONG_INPUTS, TRUE, WRONG_POINTER);

	return output;
}

output get_wrong_output(const type type_, void* type_error_warning_, const boolean is_error_, void* further_)
{
	output output = get_new_output(WRONG_POINTER, type_);

	return *update_output_log(&output, type_error_warning_, is_error_, further_);
}

char* output_to_string(const output* output_)
{
	if (output_ == WRONG_POINTER) return WRONG_STRING;

	return WRONG_STRING;
}

output* update_output_log(output* output_, void* type_error_warning_, const boolean is_error_, void* further_)
{
	output_->_is_ok = FALSE;
	output_->_log = get_new_log(type_error_warning_, is_error_, further_);

	return output_;
}
