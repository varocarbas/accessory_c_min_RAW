#include "headers/strings.h"

size_t get_string_length(char* input_)
{
	char* input = __trim(input_);

	size_t output = get_string_length_internal(input);

	free(input);

	return output;
}

boolean string_is_ok(char* input_)
{
	char* input = __trim(input_);

	boolean output = string_is_ok_internal(input);

	free(input);

	return output;
}

boolean strings_are_equal(char* input1_, char* input2_) { return strings_are_equal_internal(input1_, input2_, TRUE); }

char* __trim(char* input_)
{
	size_t start_length[2];

	trim_start_length_internal(start_length, input_);

	return (start_length[1] > WRONG_SIZE ? __substring(input_, start_length[0], start_length[1]) : __get_wrong_string_heap());
}

char* __substring(char* input_, const size_t start_i_, const size_t length_)
{
	char* output = __initialise_string(length_);

	_substring_internal(output, input_, start_i_, length_, TRUE);

	return output;
}

char* _get_wrong_string(boolean is_heap_) { return (is_heap_ ? __get_wrong_string_heap() : get_wrong_string_stack()); }

char* get_wrong_string_stack() { return WRONG_STRING; }

char* __get_wrong_string_heap() { return add_string_termination_internal((char*)__malloc(0, STRING), 0); }

char* __initialise_string(const size_t length_) { return (length_ != WRONG_SIZE ? (char*)__malloc(length_, STRING) : __get_wrong_string_heap()); }

char* __assign_string(char* input_) { return __assign_free_string_internal(input_, FALSE); }

char* __assign_free_string(char* input_h_) { return __assign_free_string_internal(input_h_, TRUE); }

char* __assign_free_output_string(char* output_h_, char* input_)
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

char* boolean_to_string(boolean input_) { return (input_ == TRUE ? "true" : "false"); }

size_t get_string_length_internal(const char* input_) { return strlen(input_); }

boolean string_is_ok_internal(char* input_) { return get_string_length_internal(input_) > WRONG_SIZE; }

boolean strings_are_equal_internal(char* input1_, char* input2_, boolean trim_)
{
	int output = -1;

	if (trim_)
	{
		char* input1 = __trim(input1_);
		char* input2 = __trim(input2_);

		output = strcmp(to_constant(input1), to_constant(input2));

		free(input1);
		free(input2);
	}
	else output = strcmp(input1_, input2_);

	return (output == 0 ? TRUE : FALSE);
}

void trim_start_length_internal(size_t* output_s_2_, char* input_)
{
	output_s_2_[0] = 0;
	output_s_2_[1] = 0;

	size_t length = get_string_length_internal(input_);

	if (length == WRONG_SIZE) return;

	size_t min_i = 0;
	size_t max_i = length - 1;

	output_s_2_[0] = min_i;
	output_s_2_[1] = length;

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

void _substring_internal(char* output_, char* input_, const size_t start_i_, const size_t length_, const boolean is_heap_)
{
	size_t length0 = get_string_length_internal(input_);

	if (length0 == WRONG_SIZE || length_ == WRONG_SIZE || start_i_ + length_ > length0)
	{
		output_ = (is_heap_ == TRUE ? __assign_free_output_string(output_, __get_wrong_string_heap()) : get_wrong_string_stack());

		return;
	}

	size_t i = 0;
	size_t i2 = start_i_;

	while (i < length_ && i2 < length0)
	{
		output_[i] = input_[i2];

		i++;
		i2++;
	}

	output_ = add_string_termination_internal(output_, length_);
}

char* add_string_termination_internal(char* input_, size_t length_)
{
	input_[length_] = '\0';

	return input_;
}

char* __assign_free_string_internal(char* input_, boolean free_input_)
{
	char* output = strcpy(__initialise_string(get_string_length(input_)), input_);

	if (free_input_) free(input_);

	return output;
}

void print_string_internal(char* input_, const boolean add_new_line_) { print_internal(input_, get_string_format(), STRING, add_new_line_); }
