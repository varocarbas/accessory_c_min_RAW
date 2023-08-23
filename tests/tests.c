#include "tests.h"

char* _assessment;

int main()
{
	run_tests();

	return 0;
}

void run_tests()
{
	_assessment = __get_wrong_string_heap();

	run_tests_strings();

	run_tests_arrays();

	free_string(_assessment);
}

void run_tests_strings()
{
	print_string("--- STRINGS\n");

	char* string_s = " abc ";
	char* string_h = __get_wrong_string_heap();
	char* string2_h = __get_wrong_string_heap();
	char* string3_h = __get_wrong_string_heap();
	char* string4_h = __get_wrong_string_heap();
	char* string5_h = __get_wrong_string_heap();

	output* output_ = __get_wrong_output();

	boolean boolean_ = WRONG_BOOLEAN;
	size_t size = WRONG_SIZE;
	size_t size2 = WRONG_SIZE;

	//1
	int count = 1;

	string_h = __assign_free_both_string(string_h, __get_wrong_string_heap());

	boolean_ = string_is_ok(string_h);

	printf("%d -- string_is_ok: |%s| -> %s (%s)\n\n", count, string_h, boolean_to_string(boolean_), get_assessment(boolean_ == FALSE ? TRUE : FALSE));

	//2
	count++;

	string_h = __assign_free_both_string(string_h, __get_wrong_string_heap());

	string2_h = __assign_free_out_string(string2_h, WRONG_STRING);

	boolean_ = strings_are_equal(string_h, string2_h);

	printf("%d -- strings_are_equal: |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, boolean_to_string(boolean_), get_assessment(boolean_));

	//3
	count++;

	string_h = __assign_free_both_string(string_h, __trim_string(string_s));

	size = get_string_length(string_h);
	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	printf("%d -- __trim_string + get_string_length: |%s| -> %s (%s)\n\n", count, string_s, string2_h, get_assessment(size == 3 ? TRUE : FALSE));

	//4
	count++;

	string2_h = __assign_free_out_string(string2_h, " ABc");

	string_h = __assign_free_both_string(string_h, __normalise_string(string2_h));

	printf("%d -- __normalise_string: |%s| -> |%s| (%s)\n\n", count, string2_h, string_h, get_assessment(strings_are_equal(string_s, string2_h)));

	//5
	count++;

	size = 1;
	size2 = 2;

	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));
	string3_h = __assign_free_both_string(string3_h, __size_to_string(size2));

	string_h = __assign_free_both_string(string_h, __substring(string_s, size, size2));

	printf("%d -- __substring: |%s|, %s, %s -> |%s| (%s)\n\n", count, string_s, string2_h, string3_h, string_h, get_assessment(strings_are_equal(string_h, "ab")));

	//6
	count++;

	size = 5;

	char* strings[] = { " ", "a", "b", "c", " " };
	string2_h = __assign_free_both_string(string2_h, __array_to_string(strings, size, STRING));

	string3_h = __assign_free_both_string(string3_h, __size_to_string(size));

	string_h = __assign_free_both_string(string_h, __concatenate_strings(strings, size));

	printf("%d -- __concatenate_strings: %s, %s -> |%s| (%s)\n\n", count, string2_h, string3_h, string_h, get_assessment(strings_are_equal(string_h, string_s)));

	//7
	count++;

	string_h = __assign_free_out_string(string_h, "b");
	string2_h = __assign_free_out_string(string2_h, string_s);

	size = 0;
	string3_h = __assign_free_both_string(string3_h, __size_to_string(size));

	output_ = __assign_free_both_void(output_, __index_of_string(string_h, string2_h, size), OUTPUT);

	string4_h = __assign_free_both_string(string4_h, __output_to_string(output_));

	printf("%d -- __index_of_string: |%s|, |%s|, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, get_assessment(output_->_is_ok == TRUE));

	//8
	count++;

	string_h = __assign_free_out_string(string_h, "b");
	string2_h = __assign_free_out_string(string2_h, string_s);

	output_ = __assign_free_both_void(output_, __split_string(string_h, string2_h), OUTPUT);

	string3_h = __assign_free_both_string(string3_h, __output_to_string(output_));

	printf("%d -- __split_string: |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(output_->_is_ok == TRUE));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);
	free_string(string5_h);

	free_output(output_);

	print_string("STRINGS ---\n");
}

void run_tests_arrays()
{
	print_string("--- ARRAYS\n");

	char** strings;
	size_t strings_size = WRONG_SIZE;

	char* string_h = __get_wrong_string_heap();
	char* string2_h = __get_wrong_string_heap();
	char* string3_h = __get_wrong_string_heap();

	size_t size = WRONG_SIZE;
	size_t i = WRONG_SIZE;
	type type_ = WRONG_TYPE;

	//1
	int count = 1;

	type_ = INT;
	size = 2;

	int ints[] = { 10, 20 };

	string_h = __assign_free_both_string(string_h, __array_to_string(ints, size, type_));

	i = 0;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	int int1 = void_to_int(get_1d_array_value(ints, i, type_));

	string3_h = __assign_free_both_string(string3_h, __int_to_string(int1));

	int int2 = get_int_array_value(ints, i);

	printf("%d -- get_1d_array_value/get_int_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment((int1 == int2) ? TRUE : FALSE));

	//2
	count++;

	type_ = STRING;

	strings_size = 2;

	strings = __initialise_string_array(strings_size);

	i = 0;
	strings = __update_string_array(strings, "abc", i);

	i++;
	strings[i] = __assign_free_out_string(strings[i], "123");

	string_h = __assign_free_both_string(string_h, __array_to_string(strings, strings_size, type_));

	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	char* string1 = void_to_string(get_2d_array_value(strings, i, type_));

	char* string2 = get_string_array_value(strings, i);

	printf("%d -- get_2d_array_value/get_string_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string1, get_assessment(strings_are_equal(string1, string2) ? TRUE : FALSE));

	//3
	count++;

	free_array(strings, strings_size, type_);

	strings_size = 5;
	strings = __initialise_string_array(strings_size);

	for (size_t i = 0; i < strings_size; i++)
	{
		char* temp = __size_to_string(i);

		strings = __update_string_array(strings, temp, i);

		free_string(temp);
	}

	type_ = STRING;

	string_h = __assign_free_both_string(string_h, __array_to_string(strings, strings_size, type_));

	size = 2;
	strings = __shrink_array_internal(strings, size, type_, WRONG_POINTER, TRUE, strings_size);

	strings_size = size;

	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	string3_h = __assign_free_both_string(string3_h, __array_to_string(strings, size, type_));

	printf("%d -- __shrink_array: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(array_is_ok(strings, size, type_)));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);

	free_string_array(strings, strings_size);

	print_string("ARRAYS ---\n");
}

char* get_assessment(const boolean is_ok_)
{
	_assessment = __assign_free_out_string(_assessment, (is_ok_ == TRUE ? "OK" : "ERROR"));

	return _assessment;
}
