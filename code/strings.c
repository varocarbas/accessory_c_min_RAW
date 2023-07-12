#include "headers/strings.h"

char* assign_string(char* out_, char* in_) { return ((out_ != WRONG_POINTER && string_is_ok(in_) == TRUE) ? assign(out_, in_, STRING, WRONG_SIZE) : get_wrong_string_stack()); }

char* __initialise_string(const size_t length_) { return __initialise(length_, STRING, FALSE); }

char* __assign_string(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __assign(in_, length, STRING, FALSE) : __assign_wrong_string());
}

char* __assign_free_in_string(char* in_h_)
{
	size_t length = get_string_length_internal(in_h_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_in(in_h_, length, STRING, FALSE) : __assign_free_wrong_string(in_h_));
}

char* __assign_free_out_string(char* out_h_, char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_out(out_h_, in_, length, STRING, FALSE) : __assign_free_wrong_string(out_h_));
}

char* __assign_free_both_string(char* out_h_, char* in_h_)
{
	size_t length = get_string_length_internal(in_h_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_both(out_h_, in_h_, length, STRING, FALSE) : __assign_free_both_wrong_string(out_h_, in_h_));
}

char* __assign_wrong_string() { return __assign_wrong(0, STRING, FALSE); }

char* __assign_free_wrong_string(char* in_out_h_) { return __assign_free_wrong(in_out_h_, 0, STRING, FALSE); }

char* __assign_free_both_wrong_string(char* out_h_, char* in_h_) { return __assign_free_both_wrong(out_h_, in_h_, 0, STRING, FALSE); }

char* _get_wrong_string(const boolean is_heap_) { return _get_wrong(STRING, FALSE, is_heap_); }

void* get_wrong_string_stack() { return get_wrong_stack(STRING, FALSE); }

void* __get_wrong_string_heap() { return __get_wrong_heap(STRING, FALSE); }

size_t get_string_length(const char* in_) { return get_string_length_internal(in_, TRUE); }

boolean string_is_ok(const char* in_) { return string_is_ok_internal(in_, TRUE); }

boolean strings_are_equal(const char* input1_, const char* input2_) { return strings_are_equal_internal(input1_, input2_, TRUE); }

char* __trim(const char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __trim_internal(in_, length) : __get_wrong_string_heap());
}

char* __substring(const char* in_, const size_t start_i_, const size_t length_) { return _substring_internal(__initialise_string(length_), in_, start_i_, length_, TRUE); }

char* __concatenate(const char* input1_, const char* input2_)
{
	size_t length1 = get_string_length_internal(input1_, FALSE);
	size_t length2 = get_string_length_internal(input2_, FALSE);

	return ((length1 != WRONG_SIZE && length2 != WRONG_SIZE) ? __concatenate_internal(input1_, length1, input2_, length2) : __get_wrong_string_heap());
}

void print_string(char* in_) { print((string_is_ok(in_) == TRUE ? in_ : WRONG_STRING), STRING); }

char* get_string_format() { return get_type_format(STRING); }

char* _value_to_string(void* value_, const type type_) { return (type_is_custom(type_) == TRUE ? custom_value_to_string(value_, type_) : __native_value_to_string(value_, type_)); }

char* custom_value_to_string(void* value_, const type type_)
{
	char* out;

	if (type_ == TYPE) out = type_to_string(generic_to_type(value_));
	else if (type_ == ERROR) out = get_error_message(generic_to_error(value_), WRONG_POINTER);
	else if (type_ == WARNING) out = get_warning_message(generic_to_warning(value_), WRONG_POINTER);
	else if (type_ == ERROR_WARNING) out = error_warning_to_string(generic_to_error_warning(value_));
	else if (type_ == OUTPUT) out = output_to_string(generic_to_output(value_));
	else if (type_ == BOOLEAN) out = boolean_to_string(generic_to_boolean(value_));
	else out = WRONG_STRING;

	return out;
}

char* __native_value_to_string(void* value_, const type type_)
{
	char* out;

	if (type_ == STRING) out = __assign_string(generic_to_string(value_));
	else if (type_ == CHAR) out = __char_to_string(generic_to_char(value_));
	else if (type_ == INT) out = __int_to_string(generic_to_int(value_));
	else if (type_ == SIZE) out = __size_to_string(generic_to_size(value_));
	else if (type_ == SHORT) out = __short_to_string(generic_to_short(value_));
	else if (type_ == LONG) out = __long_to_string(generic_to_long(value_));
	else if (type_ == DOUBLE) out = __double_to_string(generic_to_double(value_));
	else out = __get_wrong_string_heap();

	return out;
}

char* type_to_string(const type in_)
{
	char* out;

	if (in_ == TYPE) out = "type";
	else if (in_ == ERROR) out = "error";
	else if (in_ == WARNING) out = "warning";
	else if (in_ == ERROR_WARNING) out = "error_warning";
	else if (in_ == OUTPUT) out = "output";
	else if (in_ == BOOLEAN) out = "boolean";
	else if (in_ == STRING) out = "string";
	else if (in_ == CHAR) out = "char";
	else if (in_ == INT) out = "int";
	else if (in_ == SIZE) out = "size";
	else if (in_ == SHORT) out = "short";
	else if (in_ == LONG) out = "long";
	else if (in_ == DOUBLE) out = "double";
	else out = WRONG_STRING;

	return out;
}

char* error_warning_to_string(const error_warning* in_)
{
	if (in_ == WRONG_ERROR_WARNING) return WRONG_STRING;

	char* out = WRONG_STRING;

	return out;
}

char* output_to_string(const output* in_)
{
	if (in_ == WRONG_OUTPUT) return WRONG_STRING;

	char* out = WRONG_STRING;

	return out;
}

char* boolean_to_string(const boolean in_) { return (in_ == TRUE ? "true" : "false"); }

char* __char_to_string(const char in_)
{
	type type = CHAR;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __int_to_string(const int in_)
{
	type type = INT;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __size_to_string(const size_t in_)
{
	type type = SIZE;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __short_to_string(const short in_)
{
	type type = SHORT;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __long_to_string(const long in_)
{
	type type = LONG;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __double_to_string(const double in_)
{
	type type = DOUBLE;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (out == WRONG_POINTER) out = __get_wrong_string_heap();
	else snprintf(out, size, format, in_);

	return out;
}

char* __normalise_string(const char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __normalise_string_internal(in_, length) : __get_wrong_string_heap());
}

char* __string_to_lower(const char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __string_to_lower_internal(in_, length) : __get_wrong_string_heap());
}

output* __index_of_string(const char* needle_, const char* haystack_, const size_t start_i_) { return ((string_is_ok(needle_) == TRUE && string_is_ok(haystack_) == TRUE) ? __index_of_string_internal(__get_new_output_type(SIZE), needle_, haystack_, TRUE, start_i_) : __get_wrong_output_error(SIZE, ERROR_WRONG_INPUTS, "index_of_string")); }

size_t get_string_length_internal(const char* in_, const boolean trim_)
{
	size_t out = WRONG_SIZE;

	if (trim_ == TRUE)
	{
		char* in = __trim_internal(in_, WRONG_SIZE);

		out = strlen(in);

		free_(in, STRING);
	}
	else out = strlen(in_);

	return out;
}

boolean string_is_ok_internal(const char* in_, const boolean trim_) { return (get_string_length_internal(in_, trim_) > WRONG_SIZE); }

boolean strings_are_equal_internal(const char* in1_, const char* in2_, const boolean normalise_)
{
	int out = -1;

	if (normalise_ == TRUE)
	{
		char* in1 = __normalise_string(in1_);
		char* in2 = __normalise_string(in2_);

		out = strcmp(in1, in2);

		free_(in1, STRING);
		free_(in2, STRING);
	}
	else out = strcmp(in1_, in2_);

	return (out == 0 ? TRUE : FALSE);
}

char* __trim_internal(const char* in_, const size_t length_)
{
	size_t* start_length = __trim_start_length_internal(in_, (length_ > WRONG_SIZE ? length_ : get_string_length_internal(in_, FALSE)));

	char* out = (start_length[1] > WRONG_SIZE ? __substring(in_, start_length[0], start_length[1]) : __get_wrong_string_heap());

	free_(start_length, SIZE);

	return out;
}

size_t* __trim_start_length_internal(const char* in_, const size_t length_)
{
	size_t* out = __initialise_array(2, SIZE);

	size_t min_i = 0;
	size_t max_i = length_ - 1;

	out[0] = min_i;
	out[1] = length_;

	for (size_t i = 0; i < 2; i++)
	{
		size_t i2 = 0;

		if (i == 0) i2 = min_i;
		else
		{
			if (out[0] > max_i)
			{
				out[0] = 0;
				out[1] = 0;

				return out;
			}

			i2 = max_i;

			out[1] -= out[0];
		}

		while (TRUE)
		{
			if (in_[i2] != ' ') break;

			if (i == 0)
			{
				out[i]++;

				i2++;
				if (i2 > max_i) break;
			}
			else
			{
				out[i]--;

				i2--;
				if (i2 < min_i) break;
			}
		}
	}

	return out;
}

char* _substring_internal(char* out_, const char* in_, const size_t start_i_, const size_t length_, const boolean is_heap_)
{
	size_t length0 = get_string_length_internal(in_, FALSE);

	if (length0 == WRONG_SIZE || length_ == WRONG_SIZE || start_i_ + length_ > length0)
	{
		out_ = (is_heap_ == TRUE ? __assign_free_both_string(out_, __get_wrong_string_heap()) : get_wrong_string_stack());
	}
	else out_ = substring_common_internal(out_, in_, start_i_, length_, length0);

	return out_;
}

char* substring_common_internal(char* out_, const char* in_, const size_t start_i_, const size_t length_, const size_t length0_)
{
	size_t i = 0;
	size_t i2 = start_i_;

	while (i < length_ && i2 < length0_)
	{
		out_[i] = in_[i2];

		i++;
		i2++;
	}

	return add_string_termination_internal(out_, length_);
}

char* __concatenate_internal(const char* in1_, const size_t length1_, const char* in2_, const size_t length2_)
{
	size_t length0 = length1_ + length2_;

	char* out = __initialise_string(length0);

	size_t count = 0;
	size_t i2 = 0;

	while (count < 2)
	{
		count++;

		for (size_t i = 0; i < (count == 1 ? length1_ : length2_); i++)
		{
			out[i2] = (count == 1 ? in1_[i] : in2_[i]);

			i2++;
		}
	}

	return out;
}

char* add_string_termination_internal(char* out_, const size_t length_)
{
	out_[length_] = STRING_TERMINATION;

	return out_;
}

void print_string_internal(char* in_, const boolean add_new_line_) { print_internal(in_, get_string_format(), STRING, add_new_line_); }

char* __normalise_string_internal(const char* in_, const size_t length_)
{
	char* temp = __trim_internal(in_, length_);

	char* out = __string_to_lower_internal(temp, length_);

	free_(temp, STRING);

	return out;
}

char* __string_to_lower_internal(const char* in_, const size_t length_)
{
	char* out = __initialise_string(length_);

	for (size_t i = 0; i < length_; i++) { out[i] = tolower(in_[i]); }

	return out;
}

output* __index_of_string_internal(output* out_, const char* needle_, const char* haystack_, const boolean normalise_, const size_t start_i_)
{
	if (normalise_)
	{
		char* needle = __normalise_string(needle_);

		out_ = __index_of_string_common_internal(out_, needle, haystack_, normalise_, start_i_);

		free_(needle, STRING);
	}
	else out_ = __index_of_string_common_internal(out_, needle_, haystack_, normalise_, start_i_);

	return out_;
}

output* __index_of_string_common_internal(output* out_, const char* needle_, const char* haystack_, const boolean normalise_, const size_t start_i_)
{
	size_t length_needle = get_string_length_internal(needle_, FALSE);
	size_t length_haystack = get_string_length_internal(haystack_, FALSE);

	boolean is_ok = TRUE;
	size_t max_i = 0;

	if (length_needle > length_haystack) is_ok = FALSE;
	else
	{
		max_i = length_haystack - length_needle;

		if (start_i_ > max_i) is_ok = FALSE;
	}

	if (is_ok == FALSE) return __update_output_error_warning_error(out_, ERROR_WRONG_INPUTS, "index_of_string_common_internal");

	size_t value = 0;
	is_ok = FALSE;

	for (size_t i = start_i_; i <= max_i; i++)
	{
		char* temp = substring_common_internal(__initialise_string(length_needle), haystack_, i, length_needle, length_haystack);

		if (normalise_)
		{
			temp = __assign_free_both_string(temp, __string_to_lower(temp));

			is_ok = strings_are_equal_internal(temp, needle_, FALSE);
		}
		else is_ok = strings_are_equal_internal(temp, needle_, FALSE);

		free_(temp, STRING);

		if (is_ok == TRUE)
		{
			value = i;

			break;
		}
	}

	if (is_ok == TRUE) out_->_value = (void*)value;
	else out_ = update_output_error_warning_warning(out_, WARNING_NOT_FOUND, "index_of_string_common_internal");

	return out_;
}
