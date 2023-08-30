#include "tests.h"

int main()
{
	run_tests();

	return 0;
}

void run_tests()
{
	run_tests_strings();

	run_tests_arrays();

	run_tests_structs();
}

void run_tests_strings()
{
	print_start("strings");

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

	printf("%d -- __index_of_string: |%s|, |%s|, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, get_assessment(output_->_is_ok));

	//8
	count++;

	string_h = __assign_free_out_string(string_h, "b");
	string2_h = __assign_free_out_string(string2_h, string_s);

	output_ = __assign_free_both_void(output_, __split_string(string_h, string2_h), OUTPUT);

	string3_h = __assign_free_both_string(string3_h, __output_to_string(output_));

	printf("%d -- __split_string: |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(output_->_is_ok));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);
	free_string(string5_h);

	free_output(output_);

	print_end("strings");
}

void run_tests_arrays()
{
	print_start("arrays");

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

	int int1 = void_to_int(get_array_value(ints, i, type_));

	string3_h = __assign_free_both_string(string3_h, __int_to_string(int1));

	int int2 = get_int_array_value(ints, i);

	printf("%d -- get_array_value/get_int_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment((int1 == int2) ? TRUE : FALSE));

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

	char* string1 = void_to_string(get_array_value(strings, i, type_));

	char* string2 = get_string_array_value(strings, i);

	printf("%d -- get_array_value/get_string_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string1, get_assessment(strings_are_equal(string1, string2)));

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

	print_end("arrays");
}

void run_tests_structs()
{
	print_start("structs");

	output** outputs;
	size_t outputs_size = WRONG_SIZE;

	output** outputs2;
	size_t outputs2_size = WRONG_SIZE;

	output* output_ = __get_wrong_output();
	output* output2 = __get_wrong_output();

	error_warning* error_warning_ = __get_wrong_error_warning();
	error_warning* error_warning2 = __get_wrong_error_warning();

	char* string_h = __get_wrong_string_heap();
	char* string2_h = __get_wrong_string_heap();

	boolean boolean_ = WRONG_BOOLEAN;
	double double_ = WRONG_DOUBLE;

	type type_ = WRONG_TYPE;
	size_t i = WRONG_SIZE;

	//1
	int count = 1;

	string_h = __assign_free_both_string(string_h, __output_to_string(output_));
	string2_h = __assign_free_both_string(string2_h, __output_to_string(output2));

	boolean_ = outputs_are_equal(output_, output2);

	printf("%d -- outputs_are_equal: %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//2
	count++;

	string_h = __assign_free_both_string(string_h, __error_warning_to_string(error_warning_));
	string2_h = __assign_free_both_string(string2_h, __error_warning_to_string(error_warning2));

	boolean_ = error_warnings_are_equal(error_warning_, error_warning2);

	printf("%d -- error_warnings_are_equal: %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//3
	count++;

	type_ = DOUBLE;
	double_ = 123.456;
	output_ = __assign_free_both_void(output_, __get_new_output(double_pointer_to_void(&double_), WRONG_SIZE, type_), OUTPUT);

	output2 = __assign_free_both_void(output2, __split_string(WRONG_STRING, WRONG_STRING), OUTPUT);

	type_ = OUTPUT;
	outputs_size = 2;

	outputs = __initialise_array(outputs_size, type_);

	i = 0;
	outputs = _update_array(outputs, output_, i, type_);

	i++;
	outputs[i] = __update_output(outputs[i], output2);

	outputs2 = __assign_array(outputs, outputs_size, type_);
	outputs2_size = outputs_size;

	string_h = __assign_free_both_string(string_h, __array_to_string(outputs, outputs_size, type_));

	boolean_ = arrays_are_equal(outputs, outputs_size, outputs2, outputs2_size, type_);

	printf("%d -- arrays (%s): %s (%s)\n\n", count, type_to_string(type_), string_h, get_assessment(boolean_));

	free_output(output_);
	free_output(output2);

	free_error_warning(error_warning_);
	free_error_warning(error_warning2);

	free_string(string_h);
	free_string(string2_h);

	free_array(outputs, outputs_size, type_);
	free_array(outputs2, outputs2_size, type_);

	print_end("structs");
}

char* get_assessment(const boolean is_ok_) { return (is_ok_ == TRUE ? "OK" : "ERROR"); }

void print_start(char* what_) { print_start_end_internal(what_, TRUE, FALSE); }

void print_start_wrong() { print_start_end_internal(WRONG_STRING, TRUE, TRUE); }

void print_end(char* what_) { print_start_end_internal(what_, FALSE, FALSE); }

void print_end_wrong() { print_start_end_internal(WRONG_STRING, FALSE, TRUE); }

void print_start_end_internal(char* what_, const boolean is_start_, const boolean is_wrong_)
{
	char* what = (is_wrong_ == TRUE ? __assign_string("wrong") : __string_to_upper(what_));
	char* separator = (is_start_ ? "--- " : " ---");

	char** items = __initialise_string_array(2);

	size_t i = 0;
	items = __update_string_array(items, (is_start_ == TRUE ? separator : what), i);

	i++;
	items = __update_string_array(items, (is_start_ == TRUE ? what : separator), i);

	size_t size = i + 1;

	char* message = __concatenate_strings(items, size);

	print_string(message);
	print_new_line();

	free_string(what);
	free_string(message);

	free_string_array(items, size);
}
