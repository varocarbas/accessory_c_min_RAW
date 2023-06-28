#include "headers/strings.h"

size_t get_string_length(const char* input_) { return get_string_length_internal(input_, TRUE); }

boolean string_is_ok(const char* input_) { return string_is_ok_internal(input_, TRUE); }

boolean strings_are_equal(const char* input1_, const char* input2_) { return strings_are_equal_internal(input1_, input2_, TRUE); }

char* __trim(const char* input_)
{
	size_t length = get_string_length_internal(input_, FALSE);

	return (length > WRONG_SIZE ? __trim_internal(input_, length) : __get_wrong_string_heap());
}

char* __substring(const char* input_, const size_t start_i_, const size_t length_) { return _substring_internal(__initialise_string(length_), input_, start_i_, length_, TRUE); }

char* __concatenate(const char* input1_, const char* input2_)
{
	size_t length1 = get_string_length_internal(input1_, FALSE);
	size_t length2 = get_string_length_internal(input2_, FALSE);

	return ((length1 != WRONG_SIZE && length2 != WRONG_SIZE) ? __concatenate_internal(input1_, length1, input2_, length2) : __get_wrong_string_heap());
}

char* _get_wrong_string(const boolean is_heap_) { return (is_heap_ ? __get_wrong_string_heap() : get_wrong_string_stack()); }

char* get_wrong_string_stack() { return WRONG_STRING; }

char* __get_wrong_string_heap() { return add_string_termination_internal((char*)__malloc(0, STRING), 0); }

char* __initialise_string(const size_t length_) { return (length_ != WRONG_SIZE ? (char*)__malloc(length_, STRING) : __get_wrong_string_heap()); }

char* __assign_string(char* input_) { return __assign_free_string_internal(input_, FALSE); }

char* __assign_free_in_string(char* input_h_) { return __assign_free_string_internal(input_h_, TRUE); }

char* __assign_free_out_string(char* output_h_, char* input_)
{
	free(output_h_);

	output_h_ = __assign_free_string_internal(input_, FALSE);

	return output_h_;
}

char* __assign_free_both_string(char* output_h_, char* input_h_)
{
	free(output_h_);

	output_h_ = __assign_free_string_internal(input_h_, TRUE);

	return output_h_;
}

void print_string(char* input_) { print((string_is_ok(input_) == TRUE ? input_ : WRONG_STRING), STRING); }

char* get_string_format() { return get_type_format(STRING); }

char* boolean_to_string(const boolean input_) { return (input_ == TRUE ? "true" : "false"); }

char* __normalise_string(const char* input_)
{
	size_t length = get_string_length_internal(input_, FALSE);

	return (length > WRONG_SIZE ? __normalise_string_internal(input_, length) : __get_wrong_string_heap());
}

char* __string_to_lower(const char* input_)
{
	size_t length = get_string_length_internal(input_, FALSE);

	return (length > WRONG_SIZE ? __string_to_lower_internal(input_, length) : __get_wrong_string_heap());
}

output index_of_string(const char* needle_, const char* haystack_, const size_t start_i_)
{
	return ((string_is_ok(needle_) == TRUE && string_is_ok(haystack_) == TRUE) ? index_of_string_internal(needle_, haystack_, TRUE, start_i_) : get_wrong_output(SIZE, (void*)ERROR_WRONG_INPUTS, TRUE, "index_of_string"));
}

size_t get_string_length_internal(const char* input_, const boolean trim_)
{
	size_t output = WRONG_SIZE;

	if (trim_)
	{
		char* input = __trim_internal(input_, WRONG_SIZE);

		output = strlen(input);

		free(input);
	}
	else output = strlen(input_);

	return output;
}

boolean string_is_ok_internal(const char* input_, const boolean trim_) { return (get_string_length_internal(input_, trim_) > WRONG_SIZE); }

boolean strings_are_equal_internal(const char* input1_, const char* input2_, const boolean normalise_)
{
	int output = -1;

	if (normalise_)
	{
		char* input1 = __normalise_string(input1_);
		char* input2 = __normalise_string(input2_);

		output = strcmp(input1, input2);

		free(input1);
		free(input2);
	}
	else output = strcmp(input1_, input2_);

	return (output == 0 ? TRUE : FALSE);
}

char* __trim_internal(const char* input_, const size_t length_)
{
	size_t length = (length_ > WRONG_SIZE ? length_ : get_string_length_internal(input_, FALSE));

	size_t start_length[2];

	trim_start_length_internal(start_length, input_, length);

	return (start_length[1] > WRONG_SIZE ? __substring(input_, start_length[0], start_length[1]) : __get_wrong_string_heap());
}

void trim_start_length_internal(size_t* output_s_2_, const char* input_, const size_t length_)
{
	output_s_2_[0] = 0;
	output_s_2_[1] = 0;

	size_t min_i = 0;
	size_t max_i = length_ - 1;

	output_s_2_[0] = min_i;
	output_s_2_[1] = length_;

	for (size_t i = 0; i < 2; i++)
	{
		size_t i2 = 0;

		if (i == 0) i2 = min_i;
		else
		{
			if (output_s_2_[0] > max_i)
			{
				output_s_2_[0] = 0;
				output_s_2_[1] = 0;

				return;
			}

			i2 = max_i;

			output_s_2_[1] -= output_s_2_[0];
		}

		while (TRUE)
		{
			if (input_[i2] != ' ') break;

			if (i == 0)
			{
				output_s_2_[i]++;

				i2++;
				if (i2 > max_i) break;
			}
			else
			{
				output_s_2_[i]--;

				i2--;
				if (i2 < min_i) break;
			}
		}
	}
}

char* _substring_internal(char* output_, const char* input_, const size_t start_i_, const size_t length_, const boolean is_heap_)
{
	size_t length0 = get_string_length_internal(input_, FALSE);

	if (length0 == WRONG_SIZE || length_ == WRONG_SIZE || start_i_ + length_ > length0)
	{
		output_ = (is_heap_ == TRUE ? __assign_free_out_string(output_, __get_wrong_string_heap()) : get_wrong_string_stack());
	}
	else output_ = _substring_common_internal(output_, input_, start_i_, length_, length0);

	return output_;
}

char* _substring_common_internal(char* output_, const char* input_, const size_t start_i_, const size_t length_, const size_t length0_)
{
	size_t i = 0;
	size_t i2 = start_i_;

	while (i < length_ && i2 < length0_)
	{
		output_[i] = input_[i2];

		i++;
		i2++;
	}

	return add_string_termination_internal(output_, length_);
}

char* __concatenate_internal(const char* input1_, const size_t length1_, const char* input2_, const size_t length2_)
{
	size_t length0 = length1_ + length2_;

	char* output = __initialise_string(length0);

	size_t count = 0;
	size_t i2 = 0;

	while (count < 2)
	{
		count++;

		for (size_t i = 0; i < (count == 1 ? length1_ : length2_); i++)
		{
			output[i2] = (count == 1 ? input1_[i] : input2_[i]);

			i2++;
		}
	}

	return output;
}

char* add_string_termination_internal(char* output_, const size_t length_)
{
	output_[length_] = '\0';

	return output_;
}

char* __assign_free_string_internal(char* input_, boolean free_input_)
{
	char* output = strcpy(__initialise_string(get_string_length_internal(input_, FALSE)), input_);

	if (free_input_) free(input_);

	return output;
}

void print_string_internal(char* input_, const boolean add_new_line_) { print_internal(input_, get_string_format(), STRING, add_new_line_); }

char* __normalise_string_internal(const char* input_, const size_t length_) { return __string_to_lower_internal(__assign_free_in_string(__trim_internal(input_, length_)), length_); }

char* __string_to_lower_internal(const char* input_, const size_t length_)
{
	char* output = __initialise_string(length_);

	for (size_t i = 0; i < length_; i++) { output[i] = tolower(input_[i]); }

	return output;
}

output index_of_string_internal(const char* needle_, const char* haystack_, const boolean normalise_, const size_t start_i_)
{
	output output;

	if (normalise_)
	{
		char* needle = __normalise_string(needle_);

		output = index_of_string_common_internal(needle, haystack_, normalise_, start_i_);

		free(needle);
	}
	else output = index_of_string_common_internal(needle_, haystack_, normalise_, start_i_);

	return output;
}

output index_of_string_common_internal(const char* needle_, const char* haystack_, const boolean normalise_, const size_t start_i_)
{
	output output = get_new_output(0, SIZE);

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

	if (is_ok == FALSE) return *update_output_log(&output, (void*)ERROR_WRONG_INPUTS, TRUE, "index_of_string_common_internal");

	size_t value = 0;
	is_ok = FALSE;

	for (size_t i = start_i_; i <= max_i; i++)
	{
		char* temp = _substring_common_internal(__initialise_string(length_needle), haystack_, i, length_needle, length_haystack);

		if (normalise_)
		{
			temp = __assign_free_out_string(temp, __string_to_lower(temp));

			is_ok = strings_are_equal_internal(temp, needle_, FALSE);
		}
		else is_ok = strings_are_equal_internal(temp, needle_, FALSE);

		free(temp);

		if (is_ok == TRUE)
		{
			value = i;

			break;
		}
	}

	if (is_ok == TRUE) output._value = (void*)value;
	else output = *update_output_log(&output, (void*)WARNING_NOT_FOUND, FALSE, "index_of_string_common_internal");

	return output;
}
