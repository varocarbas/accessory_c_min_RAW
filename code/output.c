#include "headers/output.h"

output* __get_new_output(void* value_, const size_t size_, const type type_)
{
	boolean is_array = output_variable_is_array_size(size_);

	output temp = { (is_array == FALSE ? __assign_void(value_, type_) : __assign_array(value_, size_, type_)), size_, type_, TRUE, WRONG_ERROR_WARNING };

	output* out = __initialise_custom(&temp, OUTPUT);

	if (output_is_ok_internal(out, FALSE) == TRUE && (value_ == WRONG_POINTER || type_ == WRONG_TYPE)) out = __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, WRONG_POINTER);
	else out->_error_warning = __get_wrong_error_warning();

	return out;
}

output* __get_new_output_type(const type type_) { return __get_new_output(get_wrong_void(type_), WRONG_SIZE, type_); }

output* __get_new_output_array(void* array_, const size_t size_, const type type_, const boolean free_variable_)
{
	output* out = __get_new_output(array_, size_, type_);

	if (free_variable_ == TRUE) free_array(array_, size_, type_);

	return out;
}

output* __get_new_output_array_min(const size_t size_) { return __get_new_output(get_wrong_array(), size_, WRONG_TYPE); }

output* __get_wrong_output() { return __get_wrong_output_error(WRONG_TYPE, WRONG_ERROR, WRONG_POINTER); }

output* __get_wrong_output_error(const type type_, const type_error error_, void* further_) { return __get_wrong_output_internal(type_, error_, WRONG_WARNING, TRUE, further_); }

output* __get_wrong_output_warning(const type type_, const type_warning warning_, void* further_) { return __get_wrong_output_internal(type_, WRONG_ERROR, warning_, FALSE, further_); }

void free_output(output* in_h_)
{
	if (output_is_ok_internal(in_h_, FALSE) == TRUE)
	{
		free_output_variable_internal(in_h_);

		free_output_error_warning_internal(in_h_);
	}

	free(in_h_);
}

output* __update_output(output* out_, output* value_)
{
	if (output_is_ok_internal(out_, FALSE) == TRUE && output_is_ok_internal(value_, FALSE) == TRUE)
	{
		*out_ = *value_;

		out_ = __assign_output_internal(out_, value_);
	}

	return out_;
}

boolean output_is_ok(output* in_) { return output_is_ok_internal(in_, DEFAULT_OUTPUT_OK_PROPERTIES); }

boolean output_variable_is_ok(output* in_) { return ((output_is_ok_internal(in_, FALSE) == TRUE && in_->_is_ok == TRUE) ? TRUE : FALSE); }

boolean output_array_variable_is_ok(output* in_) { return ((output_variable_is_array(in_) == TRUE && array_is_ok(in_->_variable, in_->_size, in_->_type) == TRUE) ? TRUE : FALSE); }

boolean output_variable_is_array(output* in_) { return ((output_is_ok_internal(in_, FALSE) == TRUE && output_variable_is_array_size(in_->_size)) ? TRUE : FALSE); }

boolean output_variable_is_array_size(const size_t size_) { return is_array(size_); }

boolean outputs_are_equal(output* in1_, output* in2_)
{
	boolean out = FALSE;

	boolean is_ok1 = output_is_ok_internal(in1_, TRUE);
	boolean is_ok2 = output_is_ok_internal(in2_, TRUE);

	if (is_ok1 == FALSE || is_ok2 == FALSE) out = (is_ok1 == is_ok2 ? TRUE : FALSE);
	else
	{
		out =
		(
			(in1_->_is_ok == in2_->_is_ok) && output_variables_are_equal_internal(in1_, in2_) &&
			error_warnings_are_equal(in1_->_error_warning, in2_->_error_warning)
		);
	}

	return out;
}

type get_output_type_variable(output* in_, const boolean free_in_)
{
	type out = (output_variable_is_ok(in_) == TRUE ? void_to_type(in_->_variable) : WRONG_TYPE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

type_error get_output_error_variable(output* in_, const boolean free_in_)
{
	type_error out = (output_variable_is_ok(in_) == TRUE ? void_to_error(in_->_variable) : WRONG_ERROR);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

type_warning get_output_warning_variable(output* in_, const boolean free_in_)
{
	type_warning out = (output_variable_is_ok(in_) == TRUE ? void_to_warning(in_->_variable) : WRONG_WARNING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

error_warning* get_output_error_warning_variable(output* in_, const boolean free_in_)
{
	error_warning* out = (output_variable_is_ok(in_) == TRUE ? void_to_error_warning(in_->_variable) : WRONG_ERROR_WARNING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

output* get_output_output_variable(output* in_, const boolean free_in_)
{
	output* out = (output_variable_is_ok(in_) == TRUE ? void_to_output(in_->_variable) : WRONG_OUTPUT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

boolean get_output_boolean_variable(output* in_, const boolean free_in_)
{
	boolean out = (output_variable_is_ok(in_) == TRUE ? void_to_boolean(in_->_variable) : WRONG_BOOLEAN);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char* get_output_string_variable(output* in_, const boolean free_in_)
{
	char* out = (output_variable_is_ok(in_) == TRUE ? void_to_string(in_->_variable) : WRONG_STRING);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char get_output_char_variable(output* in_, const boolean free_in_)
{
	char out = (output_variable_is_ok(in_) == TRUE ? void_to_char(in_->_variable) : WRONG_CHAR);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

int get_output_int_variable(output* in_, const boolean free_in_)
{
	int out = (output_variable_is_ok(in_) == TRUE ? void_to_int(in_->_variable) : WRONG_INT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

size_t get_output_size_variable(output* in_, const boolean free_in_)
{
	size_t out = (output_variable_is_ok(in_) == TRUE ? void_to_size(in_->_variable) : WRONG_SIZE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

short get_output_short_variable(output* in_, const boolean free_in_)
{
	short out = (output_variable_is_ok(in_) == TRUE ? void_to_short(in_->_variable) : WRONG_SHORT);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

long get_output_long_variable(output* in_, const boolean free_in_)
{
	long out = (output_variable_is_ok(in_) == TRUE ? void_to_long(in_->_variable) : WRONG_LONG);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

double get_output_double_variable(output* in_, const boolean free_in_)
{
	double out = (output_variable_is_ok(in_) == TRUE ? void_to_double(in_->_variable) : WRONG_DOUBLE);

	if (free_in_ == TRUE) free_output(in_);

	return out;
}

char* __output_to_string(output* in_)
{
	char* out;

	if (output_is_ok_internal(in_, TRUE) == TRUE)
	{
		if (error_warning_is_ok_internal(in_->_error_warning, TRUE) == FALSE)
		{
			char* temp = __output_variable_to_string_full(in_);

			char* items[] = { DEFAULT_ENCLOSURE_EXTERNAL_START, temp, DEFAULT_ENCLOSURE_EXTERNAL_END };

			out = __concatenate_strings(items, 3);

			free_string(temp);
		}
		else out = __error_warning_to_string(in_->_error_warning);
	}
	else out = __get_wrong_string();

	return out;
}

char* _output_variable_to_string(output* in_)
{
	char* out;

	if (output_variable_is_array(in_) == TRUE) out = __output_array_variable_to_string_internal(in_);
	else if (output_is_ok_internal(in_, FALSE) == TRUE) out = _void_type_to_string(in_->_variable, in_->_type);
	else out = _get_wrong_string(void_type_to_string_is_heap(in_->_type));

	return out;
}

char* __output_variable_to_string_full(output* in_)
{
	char* out;

	char* value = _output_variable_to_string(in_);

	boolean is_array = output_variable_is_array(in_);

	char* type = type_to_string(in_->_type);
	if (is_array == TRUE) type = __concatenate_two_strings(type, " array");

	char* items[] = { value, " ", DEFAULT_ENCLOSURE_INTERNAL_START, type, DEFAULT_ENCLOSURE_INTERNAL_END };
	out = __concatenate_strings(items, 5);

	if (is_array == TRUE || void_type_to_string_is_heap(in_->_type) == TRUE)
	{
		free_string(value);

		if (is_array == TRUE) free_string(type);
	}

	return out;
}

output* __update_output_variable(output* out_, void* value_, const type type_)
{
	if (output_is_ok_internal(out_, FALSE) == FALSE) return out_;

	out_->_variable = __assign_free_out_void(out_->_variable, value_, type_);

	return out_;
}

output* remove_output_error_warning(output* out_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, WRONG_WARNING, FALSE, WRONG_POINTER); }

output* __update_output_error_warning_error(output* out_, const type_error error_, void* further_) { return _update_output_error_warning_internal(out_, error_, WRONG_WARNING, TRUE, further_); }

output* update_output_error_warning_warning(output* out_, const type_warning warning_, void* further_) { return _update_output_error_warning_internal(out_, WRONG_ERROR, warning_, FALSE, further_); }

output* __update_output_error_warning_conversion(output* out_, void* from_, const type type_from_, const type type_to_)
{
	char* temp = _void_type_to_string(from_, type_from_);

	char* items[] = { type_to_string(type_from_), " ", DEFAULT_ENCLOSURE_INTERNAL_START, temp, DEFAULT_ENCLOSURE_INTERNAL_END, " can't be converted into ", type_to_string(type_to_) };

	char* temp2 = __concatenate_strings(items, 7);

	out_ = _update_output_error_warning_internal(out_, ERROR_WRONG_CONVERSION, WRONG_WARNING, TRUE, temp2);

	if (void_type_to_string_is_heap(type_from_) == TRUE) free_string(temp);

	free_string(temp2);

	return out_;
}

output* __initialise_output_internal(output instance_)
{
	output* out = __initialise_void(OUTPUT);

	*out = instance_;

	return out;
}

void free_output_variable_internal(output* in_) { free_(in_->_variable, in_->_size, in_->_type); }

void free_output_error_warning_internal(output* in_) { free_error_warning(in_->_error_warning); }

output* __assign_output_internal(output* out_, output* in_)
{
	if (output_is_ok_internal(out_, FALSE) == TRUE && output_is_ok_internal(in_, FALSE) == TRUE)
	{
		out_->_variable = (output_variable_is_array(in_) == FALSE ? __assign_void(in_->_variable, in_->_type) : __assign_array(in_->_variable, in_->_size, in_->_type));

		out_->_error_warning = __assign_void(in_->_error_warning, ERROR_WARNING);
	}

	return out_;
}

boolean output_is_ok_internal(output* in_, const boolean check_properties_)
{
	boolean out = void_type_is_ok(in_, OUTPUT);

	if (out == TRUE && check_properties_ == TRUE)
	{
		if (in_->_type == WRONG_TYPE) out = FALSE;
	}

	return out;
}

boolean output_variables_are_equal_internal(output* in1_, output* in2_)
{
	boolean out = FALSE;
	if (in1_->_type != in2_->_type) return out;

	boolean is_array1 = output_variable_is_array(in1_);
	boolean is_array2 = output_variable_is_array(in2_);

	if (is_array1 == is_array2)
	{
		if (is_array1 == TRUE) out = arrays_are_equal(in1_->_variable, in1_->_size, in2_->_variable, in2_->_size, in1_->_type);
		else out = voids_are_equal(in1_->_variable, in2_->_variable, in1_->_type);
	}

	return out;
}

char* __output_array_variable_to_string_internal(output* in_)
{
	char* array = __array_to_string(in_->_variable, in_->_size, in_->_type);

	char* size = __size_to_string(in_->_size);

	char* temp2[] = { DEFAULT_ENCLOSURE_EXTERNAL_START, size, DEFAULT_SEPARATOR_ITEMS, array, DEFAULT_ENCLOSURE_EXTERNAL_END };

	char* out = __concatenate_strings(temp2, 5);

	free_string(array);
	free_string(size);

	return out;
}

output* __get_wrong_output_internal(const type type_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	output* out = __get_new_output_type(type_);

	if (output_is_ok_internal(out, FALSE) == TRUE) out = _update_output_error_warning_internal(out, error_, warning_, is_error_, further_);

	return out;
}

output* _update_output_error_warning_internal(output* out_, const type_error error_, const type_warning warning_, const boolean is_error_, void* further_)
{
	if (output_is_ok_internal(out_, FALSE) == FALSE) return out_;

	free_output_error_warning_internal(out_);

	out_->_is_ok = (is_error_ == FALSE);
	out_->_error_warning = __get_new_error_warning_internal(error_, warning_, is_error_, further_);

	return out_;
}
