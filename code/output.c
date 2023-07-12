#include "headers/output.h"

output* __get_new_output(void* value_, const type type_)
{
	output temp = { value_, type_, TRUE, WRONG_ERROR_WARNING };

	output* out = __assign_variable(&temp, OUTPUT);

	if (out != WRONG_OUTPUT && (value_ == WRONG_POINTER || type_ == WRONG_TYPE)) out = __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, WRONG_POINTER);

	return out;
}

output* __get_new_output_type(const type type_) { return __get_new_output(get_wrong_generic_stack(type_), type_); }

output* __get_wrong_output_error(const type type_, const type_error error_, void* further_) { return __get_wrong_output_internal(type_, error_, WRONG_WARNING, TRUE, further_); }

output* __get_wrong_output_warning(const type type_, const type_warning warning_, void* further_) { return __get_wrong_output_internal(type_, WRONG_ERROR, warning_, FALSE, further_); }

output* remove_output_error_warning(output* out_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, WRONG_WARNING, FALSE, WRONG_POINTER); }

output* __update_output_error_warning_error(output* out_, const type_error error_, void* further_) { return _update_output_error_warning_internal(out_, error_, WRONG_WARNING, TRUE, further_); }

output* update_output_error_warning_warning(output* out_, const type_warning warning_, void* further_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, warning_, FALSE, further_); }

output* __get_wrong_output_internal(const type type_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	output* out = __get_new_output_type(type_);

	if (out != WRONG_OUTPUT) out = _update_output_error_warning_internal(out, error_, warning_, is_error_, further_);

	return out;
}

output* _update_output_error_warning_internal(output* out_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	if (out_ == WRONG_OUTPUT) return out_;

	free_output_error_warning(out_);

	boolean is_ok = (is_error_ == FALSE);

	out_->_is_ok = is_ok;

	if (is_ok == TRUE) out_->_error_warning = assign(out_->_error_warning, WRONG_ERROR_WARNING, ERROR_WARNING, 1);
	else out_->_error_warning = __assign_free_in(__get_new_error_warning_internal(error_, warning_, is_error_, further_), 1, ERROR_WARNING, FALSE);

	return out_;
}
