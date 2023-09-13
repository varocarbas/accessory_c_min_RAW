#include "headers/strings.h"

char* __initialise_string(const size_t length_) { return __initialise(length_, STRING, FALSE); }

char** __initialise_string_array(const size_t size_) { return __initialise_array(size_, STRING); }

char* __assign_string(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __assign(in_, length, STRING, FALSE) : __get_wrong_string());
}

char* __assign_free_in_string(char* in_h_)
{
	size_t length = get_string_length_internal(in_h_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_in(in_h_, length, STRING, FALSE) : __get_wrong_string_free(in_h_));
}

char* __assign_free_out_string(char* out_h_, char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_out(out_h_, in_, length, STRING, FALSE) : __get_wrong_string_free(out_h_));
}

char* __assign_free_both_string(char* out_h_, char* in_h_)
{
	size_t length = get_string_length_internal(in_h_, FALSE);

	return (length > WRONG_SIZE ? __assign_free_both(out_h_, in_h_, length, STRING, FALSE) : __get_wrong_string_free_both(out_h_, in_h_));
}

void free_string(char* in_h_) { free_void(in_h_, STRING); }

void free_string_array(char** in_h_, const size_t size_) { free_2d_pointer(in_h_, size_, STRING); }

char* _get_wrong_string(const boolean is_heap_) { return _get_wrong(STRING, FALSE, is_heap_); }

char* get_wrong_string() { return get_wrong(STRING, FALSE); }

char* __get_wrong_string()
{
	size_t size = 0;

	char* out = __initialise_string(size);

	if (pointer_is_ok(out)) out = add_string_termination_internal(out, size);

	return out;
}

char* __get_wrong_string_free(char* in_out_h_) { return __get_wrong_free(in_out_h_, 0, STRING); }

char* __get_wrong_string_free_both(char* out_h_, char* in_h_) { return __get_wrong_free_both(out_h_, in_h_, 0, STRING); }

char* __update_string(char* out_, char* value_, const boolean free_out_)
{
	if (free_out_) free_string(out_);

	out_ = __assign_string(value_);

	return out_;
}

char** __update_string_array(char** array_, char* value_, const size_t i_) { return _update_array(array_, value_, i_, STRING); }

size_t get_string_length(char* in_) { return get_string_length_internal(in_, DEFAULT_STRINGS_LENGTH_TRIM); }

boolean string_is_ok(char* in_) { return string_is_ok_internal(in_, DEFAULT_STRINGS_OK_TRIM); }

boolean strings_are_equal(char* in1_, char* in2_) { return strings_are_equal_internal(in1_, in2_, DEFAULT_STRINGS_EQUAL_NORMALISE); }

char* __trim_string(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __trim_string_internal(in_, length) : __get_wrong_string());
}

char* __substring(char* in_, const size_t start_i_, const size_t length_) { return _substring_internal(__initialise_string(length_), in_, start_i_, length_, TRUE); }

char* __concatenate_strings(char** ins_, const size_t tot_) { return __concatenate_strings_internal(ins_, tot_, WRONG_STRING); }

char* __concatenate_two_strings(char* in1_, char* in2_)
{
	char* out;

	size_t length1 = get_string_length_internal(in1_, FALSE);
	size_t length2 = get_string_length_internal(in2_, FALSE);

	boolean length1_ok = FALSE;
	if (length1 > WRONG_SIZE) length1_ok = TRUE;

	boolean length2_ok = FALSE;
	if (length2 > WRONG_SIZE) length2_ok = TRUE;

	if (length1_ok && length2_ok) out = __concatenate_two_strings_internal(in1_, length1, in2_, length2);
	else if (length1_ok == length2_ok) out = __get_wrong_string();
	else out = __assign_string((length1_ok ? in1_ : in2_));

	return out;
}

char* __normalise_string(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __normalise_string_internal(in_, length) : __get_wrong_string());
}

char* __string_to_lower(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __string_to_lower_upper_internal(in_, length, TRUE) : __get_wrong_string());
}

char* __string_to_upper(char* in_)
{
	size_t length = get_string_length_internal(in_, FALSE);

	return (length > WRONG_SIZE ? __string_to_lower_upper_internal(in_, length, FALSE) : __get_wrong_string());
}

output* __index_of_string(char* needle_, char* haystack_, const size_t start_i_)
{
	output* out = __get_new_output_type(SIZE);

	boolean is_ok = (string_is_ok_internal(needle_, FALSE) && string_is_ok_internal(haystack_, FALSE));

	boolean is_error = !is_ok;

	int i = WRONG_I;

	if (is_ok) i = index_of_string_int_internal(needle_, haystack_, start_i_, DEFAULT_STRINGS_INDEX_OF_NORMALISE);

	if (i >= 0)
	{
		output* temp = __int_to_size(i);

		is_ok = temp->_is_ok;

		if (is_ok) out = __update_output_variable(out, temp->_variable, SIZE);

		free_output(temp);
	}

	if (!is_ok) out = (is_error ? __update_output_error_warning_error(out, ERROR_WRONG_INPUTS, string_pointer_to_void("__index_of_string")) : update_output_error_warning_warning(out, WARNING_NOT_FOUND, string_pointer_to_void("__index_of_string")));

	return out;
}

int index_of_string_int(char* needle_, char* haystack_, const size_t start_i_) { return ((string_is_ok(needle_) && string_is_ok(haystack_)) ? index_of_string_int_internal(needle_, haystack_, start_i_, DEFAULT_STRINGS_INDEX_OF_NORMALISE) : WRONG_I); }

size_t get_matches_in_string(char* needle_, char* haystack_) { return ((string_is_ok(needle_) && string_is_ok(haystack_)) ? get_matches_in_string_internal(needle_, haystack_, DEFAULT_STRINGS_MATCHES_NORMALISE) : 0); }

output* __split_string(char* needle_, char* haystack_)
{
	size_t length_needle = get_string_length_internal(needle_, FALSE);
	size_t length_haystack = get_string_length_internal(haystack_, FALSE);

	return ((length_haystack > WRONG_SIZE && length_needle > WRONG_SIZE && length_needle < length_haystack) ? __split_string_internal(needle_, length_needle, haystack_, length_haystack, DEFAULT_STRINGS_SPLIT_NORMALISE) : __get_wrong_output_error(STRING, ERROR_WRONG_INPUTS, string_pointer_to_void("__split_string")));
}

void print_string(char* in_) { print((string_is_ok(in_) ? in_ : WRONG_STRING), STRING); }

char* get_string_format() { return get_type_format(STRING); }

char* boolean_to_string(const boolean in_) { return (in_ ? "true" : "false"); }

char* __char_to_string(const char in_)
{
	type type = CHAR;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

char* __int_to_string(const int in_)
{
	type type = INT;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

char* __size_to_string(const size_t in_)
{
	type type = SIZE;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

char* __short_to_string(const short in_)
{
	type type = SHORT;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

char* __long_to_string(const long in_)
{
	type type = LONG;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

char* __double_to_string(const double in_)
{
	type type = DOUBLE;

	char* format = get_type_format(type);

	size_t size = snprintf(WRONG_POINTER, 0, format, in_) + 1;

	char* out = __initialise_internal(size);

	if (pointer_is_ok(out)) snprintf(out, size, format, in_);
	else out = __get_wrong_string();

	return out;
}

size_t get_string_length_internal(char* in_, const boolean trim_)
{
	size_t out = WRONG_SIZE;
	if (in_ == WRONG_POINTER) return out;

	if (trim_)
	{
		char* in = __trim_string_internal(in_, WRONG_SIZE);

		out = strlen(in);

		free_string(in);
	}
	else out = strlen(in_);

	return out;
}

boolean string_is_ok_internal(char* in_, const boolean trim_) { return (get_string_length_internal(in_, trim_) > WRONG_SIZE); }

boolean strings_are_equal_internal(char* in1_, char* in2_, const boolean normalise_)
{
	int out = -1;

	if (normalise_)
	{
		char* in1 = __normalise_string(in1_);
		char* in2 = __normalise_string(in2_);

		out = strcmp(in1, in2);

		free_string(in1);
		free_string(in2);
	}
	else out = strcmp(in1_, in2_);

	return (out == 0);
}

char* __trim_string_internal(char* in_, const size_t length_)
{
	char* out;

	size_t length = (length_ > WRONG_SIZE ? length_ : get_string_length_internal(in_, FALSE));

	size_t* start_length = (length > WRONG_SIZE ? __trim_string_start_length_internal(in_, length) : WRONG_POINTER);

	if (pointer_is_ok(start_length))
	{
		out = (start_length[1] > WRONG_SIZE ? __substring(in_, start_length[0], start_length[1]) : __get_wrong_string());

		free_(start_length, 2, SIZE);
	}
	else out = __get_wrong_string();

	return out;
}

size_t* __trim_string_start_length_internal(char* in_, const size_t length_)
{
	size_t* out = __initialise_array(2, SIZE);
	if (!pointer_is_ok(out)) return WRONG_POINTER;

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

char* _substring_internal(char* out_, char* in_, const size_t start_i_, const size_t length_, const boolean is_heap_)
{
	size_t length0 = get_string_length_internal(in_, FALSE);

	if (length0 == WRONG_SIZE || length_ == WRONG_SIZE || start_i_ + length_ > length0)
	{
		out_ = (is_heap_ ? __assign_free_both_string(out_, __get_wrong_string()) : get_wrong_string());
	}
	else out_ = substring_common_internal(out_, in_, start_i_, length_, length0);

	return out_;
}

char* substring_common_internal(char* out_, char* in_, const size_t start_i_, const size_t length_, const size_t length0_)
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

char* __concatenate_two_strings_internal(char* in1_, const size_t length1_, char* in2_, const size_t length2_)
{
	size_t length0 = length1_ + length2_;

	char* out = __initialise_string(length0);
	if (!pointer_is_ok(out)) return __get_wrong_string();

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

	return add_string_termination_internal(out, length0);
}

char* __concatenate_strings_internal(char** ins_, const size_t tot_, char* separator_)
{
	if (!array_is_ok(ins_, tot_, STRING) || tot_ == WRONG_SIZE) return __get_wrong_string();

	size_t i = 0;

	char* out = __concatenate_strings_add_internal(WRONG_POINTER, ins_, separator_, i);
	if (tot_ < 2) return out;

	for (i = 1; i < tot_; i++) { out = __concatenate_strings_add_internal(out, ins_, separator_, i); }

	return out;
}

char* __concatenate_strings_add_internal(char* out_, char** ins_, char* separator_, const size_t i_)
{
	if (i_ == 0) out_ = __assign_string(ins_[i_]);
	else
	{
		if (string_is_ok(separator_)) out_ = __assign_free_both_string(out_, __concatenate_two_strings(out_, DEFAULT_SEPARATOR));

		out_ = __assign_free_both_string(out_, __concatenate_two_strings(out_, ins_[i_]));
	}

	return out_;
}

char* add_string_termination_internal(char* out_, const size_t length_)
{
	out_[length_] = STRING_TERMINATION;

	return out_;
}

void print_string_internal(char* in_, const boolean add_new_line_) { print_internal(in_, get_string_format(), STRING, add_new_line_); }

char* __normalise_string_internal(char* in_, const size_t length_)
{
	char* temp = __trim_string_internal(in_, length_);

	char* out = __string_to_lower_upper_internal(temp, get_string_length_internal(temp, FALSE), TRUE);

	free_string(temp);

	return out;
}

char* __string_to_lower_upper_internal(char* in_, const size_t length_, const boolean is_lower_)
{
	char* out = __initialise_string(length_);
	if (!pointer_is_ok(out)) return __get_wrong_string();

	for (size_t i = 0; i < length_; i++) { out[i] = (is_lower_ ? tolower(in_[i]) : toupper(in_[i])); }

	return add_string_termination_internal(out, length_);
}

int index_of_string_int_internal(char* needle_, char* haystack_, const size_t start_i_, const boolean normalise_)
{
	int out;

	if (normalise_)
	{
		char* needle = __normalise_string(needle_);

		out = index_of_string_int_common_internal(needle, haystack_, start_i_);

		free_string(needle);
	}
	else out = index_of_string_int_common_internal(needle_, haystack_, start_i_);

	return out;
}

int index_of_string_int_common_internal(char* needle_, char* haystack_, const size_t start_i_)
{
	int out = WRONG_I;

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

	if (!is_ok) return out;

	is_ok = FALSE;

	for (size_t i = start_i_; i <= max_i; i++)
	{
		char* temp = __initialise_string(length_needle);
		if (!pointer_is_ok(temp)) break;

		temp = substring_common_internal(temp, haystack_, i, length_needle, length_haystack);

		is_ok = strings_are_equal_internal(temp, needle_, FALSE);

		free_string(temp);

		if (is_ok)
		{
			output* temp = __size_to_int(i);

			if (temp->_is_ok) return get_output_int_variable(temp, TRUE);
			else free_output(temp);
		}
	}

	return out;
}

size_t get_matches_in_string_internal(char* needle_, char* haystack_, const boolean normalise_)
{
	void* temp = __split_matches_string_internal(needle_, haystack_, normalise_, FALSE);

	size_t out = void_to_size(temp);

	free_void(temp, SIZE);

	return out;
}

output* __split_string_internal(char* needle_, const size_t length_needle_, char* haystack_, const size_t length_haystack_, const boolean normalise_)
{
	type type0 = STRING;

	output* temp = void_to_output(__split_matches_string_internal(needle_, haystack_, normalise_, TRUE));

	if (!output_array_variable_is_ok(temp))
	{
		free_output(temp);

		char* temp2[] = { haystack_ };

		return __get_new_output(temp2, 1, type0);
	}

	size_t* is = temp->_variable;
	size_t tot_is = temp->_size;

	size_t tot0 = tot_is + 1;

	char** items = __initialise_array(tot0, type0);

	size_t i0 = 0;
	size_t i = 0;
	size_t i2 = 0;

	size_t length = 0;
	size_t tot = 1;

	for (i0 = 0; i0 < tot_is; i0++)
	{
		if (i > is[i0]) continue;

		length = is[i0] - i;

		if (length > 0)
		{
			char* temp2 = __substring(haystack_, i, length);

			items = __update_string_array(items, string_pointer_to_void(temp2), i2);

			free_string(temp2);
		}
		else items = __update_string_array(items, string_pointer_to_void(WRONG_STRING), i2);

		i = is[i0] + length_needle_;
		i2++;
		tot++;

		if (i >= length_haystack_) break;
	}

	length = length_haystack_ - i;

	if (length > 0)
	{
		char* temp2 = __substring(haystack_, i, length);

		items = __update_string_array(items, string_pointer_to_void(temp2), i2);

		free_string(temp2);
	}
	else items = __update_string_array(items, string_pointer_to_void(WRONG_STRING), i2);

	if (tot < tot0) items = __shrink_free_array(items, tot, type0, tot0);

	free_output(temp);

	return __get_new_output_array(items, tot, STRING, TRUE);
}

void* __split_matches_string_internal(char* needle_, char* haystack_, const boolean normalise_, const boolean is_split_)
{
	size_t length_needle = get_string_length_internal(needle_, FALSE);

	type type0 = SIZE;
	size_t tot0 = WRONG_SIZE;

	size_t tot = 0;
	size_t i = 0;

	size_t* is = WRONG_POINTER;

	if (is_split_)
	{
		tot0 = (size_t)((double)get_string_length_internal(haystack_, FALSE) / length_needle);
		if (tot0 == 0) return __get_wrong_output();

		is = __initialise_array(tot0, type0);
	}

	while (TRUE)
	{
		output* temp = __int_to_size(index_of_string_int_common_internal(needle_, haystack_, i));

		if (temp->_is_ok)
		{
			if (is_split_) is = _update_array(is, temp->_variable, tot, SIZE);

			i = get_output_size_variable(temp, TRUE) + 1;

			tot++;
		}
		else
		{
			free_output(temp);

			break;
		}
	}

	void* out;

	if (is_split_)
	{
		if (tot == 0) out = __get_new_output_array_min(tot);
		else
		{
			void* temp2 = __shrink_free_array(is, tot, type0, tot0);

			output* temp3 = __get_new_output(temp2, tot, type0);

			out = output_pointer_to_void(temp3);

			free_array(temp2, tot, type0);
		}
	}
	else out = __size_to_void(tot);

	return out;
}
