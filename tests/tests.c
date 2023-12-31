#include "tests.h"

int _tot_errors = 0;

int main()
{
	run_all();

	print_last();

	return 0;
}

void run_all()
{
	run_strings();

	run_arrays();

	run_structs();

	run_io();
}

void run_strings()
{
	print_start("strings");

	char* string_s = " abc ";
	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();
	char* string4_h = __get_wrong_string();
	char* string5_h = __get_wrong_string();

	output* output_ = __get_wrong_output();

	boolean boolean_ = WRONG_BOOLEAN;

	size_t start_i = WRONG_SIZE;
	size_t size = WRONG_SIZE;

	//1
	int count = 1;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());

	boolean_ = string_is_ok(string_h);

	printf("%d -- string_is_ok: |%s| -> %s (%s)\n\n", count, string_h, boolean_to_string(boolean_), get_assessment(!boolean_));

	//2
	count++;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());

	string2_h = __assign_free_out_string(string2_h, WRONG_STRING);

	boolean_ = strings_are_equal(string_h, string2_h);

	printf("%d -- strings_are_equal: |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, boolean_to_string(boolean_), get_assessment(boolean_));

	//3
	count++;

	string_h = __assign_free_both_string(string_h, __trim_string(string_s));

	size = get_string_length(string_h);
	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	printf("%d -- __trim_string + get_string_length: |%s| -> |%s|, %s (%s)\n\n", count, string_s, string_h, string2_h, get_assessment(size == 3));

	//4
	count++;

	string_h = __assign_free_out_string(string_h, " ABc");

	string2_h = __assign_free_both_string(string2_h, __normalise_string(string_h));

	printf("%d -- __normalise_string: |%s| -> |%s| (%s)\n\n", count, string_h, string2_h, get_assessment(strings_are_equal(string_s, string2_h)));

	//5
	count++;

	start_i = 1;
	size = 2;

	string2_h = __assign_free_both_string(string2_h, __size_to_string(start_i));
	string3_h = __assign_free_both_string(string3_h, __size_to_string(size));

	string_h = __assign_free_both_string(string_h, __substring(string_s, start_i, size));

	printf("%d -- __substring: |%s|, %s, %s -> |%s| (%s)\n\n", count, string_s, string2_h, string3_h, string_h, get_assessment(strings_are_equal(string_h, "ab")));

	//6
	count++;

	size = 5;
	char* strings[] = { " ", "a", "b", "c", " " };

	string_h = __assign_free_both_string(string_h, __array_to_string(strings, size, STRING));

	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	string3_h = __assign_free_both_string(string3_h, __concatenate_strings(strings, size));

	printf("%d -- __concatenate_strings: %s, %s -> |%s| (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(strings_are_equal(string3_h, string_s)));

	//7
	count++;

	string_h = __assign_free_out_string(string_h, "b");
	string2_h = __assign_free_out_string(string2_h, string_s);

	start_i = 0;
	string3_h = __assign_free_both_string(string3_h, __size_to_string(start_i));

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__index_of_string(string_h, string2_h, start_i)), OUTPUT);

	string4_h = __assign_free_both_string(string4_h, __output_to_string(output_));

	printf("%d -- __index_of_string: |%s|, |%s|, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, get_assessment(output_->_is_ok));

	//8
	count++;

	string_h = __assign_free_out_string(string_h, "b");
	string2_h = __assign_free_out_string(string2_h, string_s);

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__split_string(string_h, string2_h)), OUTPUT);

	string3_h = __assign_free_both_string(string3_h, __output_to_string(output_));

	printf("%d -- __split_string: |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(output_->_is_ok));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);
	free_string(string5_h);

	free_output(output_);

	run_strings_wrong();

	print_end("strings");
}

void run_strings_wrong()
{
	print_start_wrong();

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();
	char* string4_h = __get_wrong_string();

	output* output_ = __get_wrong_output();

	size_t start_i = WRONG_SIZE;
	size_t size = WRONG_SIZE;

	//1
	int count = 1;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());

	string2_h = __assign_free_both_string(string2_h, __trim_string(string_h));

	size = get_string_length(string2_h);
	string3_h = __assign_free_both_string(string3_h, __size_to_string(size));

	printf("%d -- __trim_string + get_string_length (wrong): |%s| -> |%s|, %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(size == 0));

	//2
	count++;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());

	string2_h = __assign_free_both_string(string2_h, __normalise_string(string_h));

	printf("%d -- __normalise_string (wrong): |%s| -> |%s| (%s)\n\n", count, string_h, string2_h, get_assessment(strings_are_equal(string_h, string2_h)));

	//3
	count++;

	start_i = WRONG_SIZE;
	size = WRONG_SIZE;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());

	string2_h = __assign_free_both_string(string2_h, __size_to_string(start_i));
	string3_h = __assign_free_both_string(string3_h, __size_to_string(size));

	string4_h = __assign_free_both_string(string4_h, __substring(string_h, start_i, size));

	printf("%d -- __substring (wrong): |%s|, %s, %s -> |%s| (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, get_assessment(strings_are_equal(string_h, string4_h)));

	//4
	count++;

	char** strings = get_wrong_array();
	string_h = __assign_free_both_string(string_h, __array_to_string(strings, size, STRING));

	size = WRONG_SIZE;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	string3_h = __assign_free_both_string(string3_h, __concatenate_strings(strings, size));

	printf("%d -- __concatenate_strings (wrong): %s, %s -> |%s| (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(strings_are_equal(string3_h, WRONG_STRING)));

	//5
	count++;

	start_i = WRONG_SIZE;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());
	string2_h = __assign_free_both_string(string2_h, __get_wrong_string());

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__index_of_string(string_h, string2_h, start_i)), OUTPUT);

	string3_h = __assign_free_both_string(string3_h, __size_to_string(start_i));

	string4_h = __assign_free_both_string(string4_h, __output_to_string(output_));

	printf("%d -- __index_of_string (wrong): |%s|, |%s|, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, get_assessment(!output_->_is_ok));

	//6
	count++;

	string_h = __assign_free_both_string(string_h, __get_wrong_string());
	string2_h = __assign_free_both_string(string2_h, __get_wrong_string());

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__split_string(string_h, string2_h)), OUTPUT);

	string3_h = __assign_free_both_string(string3_h, __output_to_string(output_));

	printf("%d -- __split_string (wrong): |%s|, |%s| -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(!output_->_is_ok));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);

	free_output(output_);

	print_end_wrong();
}

void run_arrays()
{
	print_start("arrays");

	char** strings;
	size_t strings_size = WRONG_SIZE;

	type* types;
	size_t types_size = WRONG_SIZE;

	long* longs;
	size_t longs_size = WRONG_SIZE;

	boolean* booleans;
	size_t booleans_size = WRONG_SIZE;

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();
	char* string4_h = __get_wrong_string();
	char* string5_h = __get_wrong_string();

	boolean boolean_ = WRONG_BOOLEAN;
	type type_ = WRONG_TYPE;

	size_t size = WRONG_SIZE;
	size_t i = WRONG_SIZE;

	//1
	int count = 1;

	type_ = INT;
	size = 2;

	int ints[] = { 10, 20 };

	string_h = __assign_free_both_string(string_h, __array_to_string(ints, size, type_));

	i = 0;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	int int1 = void_to_int(get_array_item(ints, i, type_));

	string3_h = __assign_free_both_string(string3_h, __int_to_string(int1));

	int int2 = get_int_array_value(ints, i);

	printf("%d -- get_array_item/get_int_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(int1 == int2));

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

	char* string1 = void_to_string(get_array_item(strings, i, type_));

	string3_h = __assign_free_both_string(string3_h, __get_string_array_value(strings, i));

	printf("%d -- get_array_item/__get_string_array_value: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string1, get_assessment(strings_are_equal(string1, string3_h)));

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
	strings = __shrink_free_array(strings, size, type_, strings_size);

	strings_size = size;

	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	string3_h = __assign_free_both_string(string3_h, __array_to_string(strings, size, type_));

	printf("%d -- __shrink_free_array: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(array_is_ok(strings, strings_size, type_)));

	//4
	count++;

	type_ = TYPE;

	type types2[] = { ERROR, INT, OUTPUT };

	types_size = 3;
	types = __assign_array(types2, types_size, type_);

	types[0] = STRING;

	boolean_ = arrays_are_equal(types, types_size, types2, types_size, type_);

	string_h = __assign_free_both_string(string_h, __array_to_string(types, types_size, type_));

	string2_h = __assign_free_both_string(string2_h, __array_to_string(types2, types_size, type_));

	string3_h = __assign_free_both_string(string3_h, __size_to_string(types_size));

	string4_h = __assign_free_out_string(string4_h, type_to_string(type_));

	printf("%d -- arrays_are_equal: %s, %s, %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, boolean_to_string(boolean_), get_assessment(!boolean_));

	//5
	count++;

	type_ = LONG;

	long longs2[] = { 1l, 2l, 3l };

	longs_size = 3;
	size = longs_size;

	longs = __assign_array(longs2, size, type_);

	string_h = __assign_free_both_string(string_h, __array_to_string(longs, size, type_));

	longs_size = 6;
	longs = __embiggen_free_array(longs, longs_size, type_, size);

	string2_h = __assign_free_both_string(string2_h, __size_to_string(longs_size));

	string3_h = __assign_free_both_string(string3_h, __array_to_string(longs, longs_size, type_));

	printf("%d -- __embiggen_array: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(array_is_ok(longs, longs_size, type_)));

	//6
	count++;

	type_ = BOOLEAN;

	boolean booleans2[] = { TRUE, TRUE };

	booleans_size = 2;

	string_h = __assign_free_both_string(string_h, __array_to_string(booleans2, booleans_size, type_));

	i = 0;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	booleans = _update_array_wrong(__assign_array(booleans2, booleans_size, type_), i, type_);

	string3_h = __assign_free_both_string(string3_h, __array_to_string(booleans, booleans_size, type_));

	printf("%d -- _update_array_wrong: %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment((booleans[i] == WRONG_BOOLEAN)));

	//7
	count++;

	type_ = WARNING;

	type_warning target = WARNING_NOT_FOUND;

	string_h = __assign_free_out_string(string_h, warning_to_string(target));

	type_warning warnings[] = { WRONG_WARNING, target, WRONG_WARNING };
	size = 3;

	string2_h = __assign_free_both_string(string2_h, __array_to_string(warnings, size, type_));

	string3_h = __assign_free_out_string(string3_h, type_to_string(type_));

	i = WRONG_SIZE;
	string4_h = __assign_free_both_string(string4_h, __size_to_string(i));

	int i2 = index_of_array_int(warning_pointer_to_void(&target), warnings, size, type_, i);

	string5_h = __assign_free_both_string(string5_h, __int_to_string(i2));

	printf("%d -- index_of_array_int: %s, %s, %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, string5_h, get_assessment((i2 == 1)));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);
	free_string(string5_h);

	free_string_array(strings, strings_size);

	free_array(types, types_size, TYPE);
	free_array(longs, longs_size, LONG);
	free_array(booleans, booleans_size, BOOLEAN);

	run_arrays_wrong();

	print_end("arrays");
}

void run_arrays_wrong()
{
	print_start_wrong();

	char** strings;
	size_t strings_size = WRONG_SIZE;

	type* types;
	size_t types_size = WRONG_SIZE;
	type* types2;
	size_t types2_size = WRONG_SIZE;

	long* longs;
	size_t longs_size = WRONG_SIZE;

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();
	char* string4_h = __get_wrong_string();
	char* string5_h = __get_wrong_string();

	boolean boolean_ = WRONG_BOOLEAN;
	type type_ = WRONG_TYPE;

	size_t size = WRONG_SIZE;
	size_t i = WRONG_SIZE;

	//1
	int count = 1;

	type_ = INT;
	size = 0;

	int* ints = get_wrong_array();

	string_h = __assign_free_both_string(string_h, __array_to_string(ints, size, type_));

	i = WRONG_SIZE;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	int int1 = void_to_int(get_array_item(ints, i, type_));

	string3_h = __assign_free_both_string(string3_h, __int_to_string(int1));

	int int2 = get_int_array_value(ints, i);

	printf("%d -- get_array_item/get_int_array_value (wrong): %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(int1 == int2));

	//2
	count++;

	type_ = STRING;

	strings_size = 2;

	strings = __initialise_string_array(strings_size);

	i = 0;
	string_h = __assign_free_both_string(string_h, __get_wrong_string());
	strings = __update_string_array(strings, string_h, i);

	i++;
	strings[i] = __assign_free_out_string(strings[i], string_h);

	string2_h = __assign_free_both_string(string2_h, __array_to_string(strings, strings_size, type_));

	string3_h = __assign_free_both_string(string3_h, __size_to_string(i));

	char* string1 = void_to_string(get_array_item(strings, i, type_));

	string4_h = __assign_free_both_string(string4_h, __get_string_array_value(strings, i));

	printf("%d -- get_array_item/__get_string_array_value (wrong): %s, %s -> %s (%s)\n\n", count, string2_h, string3_h, string1, get_assessment(strings_are_equal(string1, string4_h)));

	//3
	count++;

	free_array(strings, strings_size, type_);

	type_ = STRING;

	strings_size = WRONG_SIZE;
	strings = __get_wrong_array();

	string_h = __assign_free_both_string(string_h, __array_to_string(strings, strings_size, type_));

	size = 0;
	strings = __shrink_free_array(strings, size, type_, strings_size);

	strings_size = size;

	string2_h = __assign_free_both_string(string2_h, __size_to_string(size));

	string3_h = __assign_free_both_string(string3_h, __array_to_string(strings, size, type_));

	printf("%d -- __shrink_free_array (wrong): %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(!array_is_ok(strings, size, type_)));

	//4
	count++;

	type_ = TYPE;

	types_size = 0;
	types = __get_wrong_array();

	types2_size = types_size;
	types2 = __get_wrong_array();

	boolean_ = arrays_are_equal(types, types_size, types2, types2_size, type_);

	string_h = __assign_free_both_string(string_h, __array_to_string(types, types_size, type_));

	string2_h = __assign_free_both_string(string2_h, __array_to_string(types2, types2_size, type_));

	string3_h = __assign_free_out_string(string3_h, type_to_string(type_));

	printf("%d -- arrays_are_equal (wrong): %s, %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, boolean_to_string(boolean_), get_assessment(boolean_));

	//5
	count++;

	type_ = LONG;

	longs_size = WRONG_SIZE;
	size = longs_size;

	longs = __get_wrong_array();

	string_h = __assign_free_both_string(string_h, __array_to_string(longs, size, type_));

	longs_size = WRONG_SIZE;
	longs = __embiggen_free_array(longs, longs_size, type_, size);

	string2_h = __assign_free_both_string(string2_h, __size_to_string(longs_size));

	string3_h = __assign_free_both_string(string3_h, __array_to_string(longs, longs_size, type_));

	printf("%d -- __embiggen_array (wrong): %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(!array_is_ok(longs, longs_size, type_)));

	//6
	count++;

	type_ = BOOLEAN;

	size = WRONG_SIZE;
	boolean* booleans2 = get_wrong_array();

	string_h = __assign_free_both_string(string_h, __array_to_string(booleans2, size, type_));

	i = WRONG_SIZE;
	string2_h = __assign_free_both_string(string2_h, __size_to_string(i));

	booleans2 = _update_array_wrong(booleans2, i, type_);

	string3_h = __assign_free_both_string(string3_h, __array_to_string(booleans2, size, type_));

	printf("%d -- _update_array_wrong (wrong): %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, get_assessment(!array_is_ok_min_internal(booleans2)));

	//7
	count++;

	type_ = WARNING;

	type_warning target = WRONG_WARNING;

	string_h = __assign_free_out_string(string_h, warning_to_string(target));

	type_warning* warnings = get_wrong_array();
	size = WRONG_SIZE;

	string2_h = __assign_free_both_string(string2_h, __array_to_string(warnings, size, type_));

	string3_h = __assign_free_out_string(string3_h, type_to_string(type_));

	i = WRONG_SIZE;
	string4_h = __assign_free_both_string(string4_h, __size_to_string(i));

	int i2 = index_of_array_int(warning_pointer_to_void(&target), warnings, size, type_, i);

	string5_h = __assign_free_both_string(string5_h, __int_to_string(i2));

	printf("%d -- index_of_array_int (wrong): %s, %s, %s, %s -> %s (%s)\n\n", count, string_h, string2_h, string3_h, string4_h, string5_h, get_assessment((i2 == WRONG_I)));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);
	free_string(string4_h);
	free_string(string5_h);

	free_string_array(strings, strings_size);

	free_array(types, types_size, TYPE);
	free_array(types2, types2_size, TYPE);

	free_array(longs, longs_size, LONG);

	print_end_wrong();
}

void run_structs()
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

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();

	boolean boolean_ = WRONG_BOOLEAN;
	double double_ = WRONG_DOUBLE;

	type type_ = WRONG_TYPE;
	size_t i = WRONG_SIZE;

	//1
	int count = 1;

	type_ = DOUBLE;
	double_ = 123.456;
	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__get_new_output(double_pointer_to_void(&double_), WRONG_SIZE, type_)), OUTPUT);

	string_h = __assign_free_both_string(string_h, __output_to_string(output_));

	output2 = __assign_free_both_void(output_pointer_to_void(output2), output_pointer_to_void(__get_new_output(double_pointer_to_void(&double_), WRONG_SIZE, type_)), OUTPUT);

	string2_h = __assign_free_both_string(string2_h, __output_to_string(output2));

	boolean_ = outputs_are_equal(output_, output2);

	printf("%d -- outputs_are_equal: %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//2
	count++;

	error_warning_ = __assign_free_both_void(error_warning_pointer_to_void(error_warning_), error_warning_pointer_to_void(__get_new_error_warning_error(ERROR_WRONG_INPUTS, "input1")), ERROR_WARNING);
	string_h = __assign_free_both_string(string_h, __error_warning_to_string(error_warning_));

	error_warning2 = __assign_free_both_void(error_warning_pointer_to_void(error_warning2), error_warning_pointer_to_void(__get_new_error_warning_error(ERROR_WRONG_INPUTS, "input1")), ERROR_WARNING);
	string2_h = __assign_free_both_string(string2_h, __error_warning_to_string(error_warning2));

	boolean_ = error_warnings_are_equal(error_warning_, error_warning2);

	printf("%d -- error_warnings_are_equal: %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//3
	count++;

	type_ = OUTPUT;
	outputs_size = 2;

	outputs = __initialise_array(outputs_size, type_);

	i = 0;
	outputs = _update_array(outputs, output_pointer_to_void(output_), i, type_);

	output2 = __assign_free_both_void(output_pointer_to_void(output2), output_pointer_to_void(__split_string("2", "123")), OUTPUT);

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

	run_structs_wrong();

	print_end("structs");
}

void run_structs_wrong()
{
	print_start_wrong();

	output** outputs;
	size_t outputs_size = WRONG_SIZE;

	output** outputs2;
	size_t outputs2_size = WRONG_SIZE;

	output* output_ = __get_wrong_output();
	output* output2 = __get_wrong_output();

	error_warning* error_warning_ = __get_wrong_error_warning();
	error_warning* error_warning2 = __get_wrong_error_warning();

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();

	boolean boolean_ = WRONG_BOOLEAN;

	type type_ = WRONG_TYPE;
	size_t i = WRONG_SIZE;

	//1
	int count = 1;

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__get_wrong_output()), OUTPUT);
	string_h = __assign_free_both_string(string_h, __output_to_string(output_));

	output2 = __assign_free_both_void(output_pointer_to_void(output2), output_pointer_to_void(__get_wrong_output()), OUTPUT);
	string2_h = __assign_free_both_string(string2_h, __output_to_string(output2));

	boolean_ = outputs_are_equal(output_, output2);

	printf("%d -- outputs_are_equal (wrong): %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//2
	count++;

	error_warning_ = __assign_free_both_void(error_warning_pointer_to_void(error_warning_), error_warning_pointer_to_void(__get_wrong_error_warning()), ERROR_WARNING);
	string_h = __assign_free_both_string(string_h, __error_warning_to_string(error_warning_));

	error_warning2 = __assign_free_both_void(error_warning_pointer_to_void(error_warning2), error_warning_pointer_to_void(__get_wrong_error_warning()), ERROR_WARNING);
	string2_h = __assign_free_both_string(string2_h, __error_warning_to_string(error_warning2));

	boolean_ = error_warnings_are_equal(error_warning_, error_warning2);

	printf("%d -- error_warnings_are_equal (wrong): %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	//3
	count++;

	type_ = OUTPUT;
	outputs_size = 2;

	outputs = __initialise_array(outputs_size, type_);

	output_ = __assign_free_both_void(output_pointer_to_void(output_), output_pointer_to_void(__get_wrong_output()), OUTPUT);

	i = 0;
	outputs = _update_array(outputs, output_pointer_to_void(output_), i, type_);

	output2 = __assign_free_both_void(output_pointer_to_void(output2), output_pointer_to_void(__get_wrong_output()), OUTPUT);

	i++;
	outputs[i] = __update_output(outputs[i], output2);

	outputs2 = __assign_array(outputs, outputs_size, type_);
	outputs2_size = outputs_size;

	string_h = __assign_free_both_string(string_h, __array_to_string(outputs, outputs_size, type_));

	boolean_ = arrays_are_equal(outputs, outputs_size, outputs2, outputs2_size, type_);

	printf("%d -- arrays (%s) (wrong): %s (%s)\n\n", count, type_to_string(type_), string_h, get_assessment(boolean_));

	free_output(output_);
	free_output(output2);

	free_error_warning(error_warning_);
	free_error_warning(error_warning2);

	free_string(string_h);
	free_string(string2_h);

	free_array(outputs, outputs_size, type_);
	free_array(outputs2, outputs2_size, type_);

	print_end_wrong();
}

void run_io()
{
	print_start("io");

	output* output_ = __get_wrong_output();

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();

	type type_ = WRONG_TYPE;
	size_t size = WRONG_SIZE;
	boolean boolean_ = WRONG_BOOLEAN;

	//1
	int count = 1;

	char* lines[] = { "1", "2", "3" };
	size = 3;

	type_ = STRING;
	string_h = __assign_free_both_string(string_h, __array_to_string(lines, size, type_));

	char* path = "test.txt";

	boolean_ = write_file_lines(path, lines, size);

	printf("%d -- write_file_lines: %s, %s (%s)\n\n", count, path, string_h, get_assessment(boolean_));

	//2
	count++;

	boolean_ = file_exists(path);

	printf("%d -- file_exists: %s (%s)\n\n", count, path, get_assessment(boolean_));

	//3
	count++;

	type_ = OUTPUT;

	output_ = __assign_free_both_void(output_, __read_file_lines(path), type_);

	string_h = __assign_free_both_string(string_h, __output_to_string(output_));

	boolean_ = (output_variable_is_ok(output_) && (output_->_type == STRING) && arrays_are_equal(lines, size, output_->_variable, output_->_size, output_->_type));

	printf("%d -- __read_file_lines: %s -> %s (%s)\n\n", count, path, string_h, get_assessment(boolean_));

	//4
	count++;

	boolean_ = delete_file(path);

	printf("%d -- delete_file: %s (%s)\n\n", count, path, get_assessment(boolean_));

	//5
	count++;

	char* items[] = { "dir1", "dir2" };
	size = 2;

	char* file = "file2.txt";

	string_h = __assign_free_both_string(string_h, __get_dir_path(items, size));

	char* items2[] = { "dir1", "dir2", file };
	size = 3;

	string2_h = __assign_free_both_string(string2_h, __get_file_path(items2, size));

	string3_h = __assign_free_both_string(string3_h, __add_to_string(string_h, file));

	boolean_ = strings_are_equal_internal(string2_h, string3_h, FALSE);

	printf("%d -- __get_dir_path/__get_file_path: %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	run_io_wrong();

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);

	free_output(output_);

	print_end("io");
}

void run_io_wrong()
{
	print_start_wrong();

	output* output_ = __get_wrong_output();

	char* string_h = __get_wrong_string();
	char* string2_h = __get_wrong_string();
	char* string3_h = __get_wrong_string();

	type type_ = WRONG_TYPE;
	size_t size = WRONG_SIZE;
	boolean boolean_ = WRONG_BOOLEAN;

	//1
	int count = 1;

	char** lines = get_wrong_array();

	type_ = STRING;
	string_h = __assign_free_both_string(string_h, __array_to_string(lines, size, type_));

	char* path = WRONG_STRING;

	boolean_ = write_file_lines(path, lines, size);

	printf("%d -- write_file_lines (wrong): %s, %s (%s)\n\n", count, path, string_h, get_assessment(!boolean_));

	//2
	count++;

	boolean_ = file_exists(path);

	printf("%d -- file_exists (wrong): %s (%s)\n\n", count, path, get_assessment(!boolean_));

	//3
	count++;

	type_ = OUTPUT;

	output_ = __assign_free_both_void(output_, __read_file_lines(path), type_);

	string_h = __assign_free_both_string(string_h, __output_to_string(output_));

	boolean_ = !output_variable_is_ok(output_);

	printf("%d -- __read_file_lines (wrong): %s -> %s (%s)\n\n", count, path, string_h, get_assessment(boolean_));

	//4
	count++;

	boolean_ = delete_file(path);

	printf("%d -- delete_file (wrong): %s (%s)\n\n", count, path, get_assessment(!boolean_));

	//5
	count++;

	char** items = get_wrong_array();
	size = WRONG_SIZE;

	char* file = WRONG_STRING;

	string_h = __assign_free_both_string(string_h, __get_dir_path(items, size));

	char** items2 = get_wrong_array();

	string2_h = __assign_free_both_string(string2_h, __get_file_path(items2, size));

	string3_h = __assign_free_both_string(string3_h, __add_to_string(string_h, file));

	boolean_ = strings_are_equal_internal(string2_h, string3_h, FALSE);

	printf("%d -- __get_dir_path/__get_file_path (wrong): %s, %s (%s)\n\n", count, string_h, string2_h, get_assessment(boolean_));

	free_string(string_h);
	free_string(string2_h);
	free_string(string3_h);

	free_output(output_);

	print_end_wrong();
}

char* get_assessment(const boolean is_ok_)
{
	char* out;

	if (is_ok_) out = "OK";
	else
	{
		_tot_errors++;

		out = "ERROR";
	}

	return out;
}

void print_start(char* what_) { print_start_end_internal(what_, TRUE, FALSE); }

void print_start_wrong() { print_start_end_internal(WRONG_STRING, TRUE, TRUE); }

void print_end(char* what_) { print_start_end_internal(what_, FALSE, FALSE); }

void print_end_wrong() { print_start_end_internal(WRONG_STRING, FALSE, TRUE); }

void print_last()
{
	char* tot = __int_to_string(_tot_errors);

	char* items[] = { "TOTAL ERRORS: ", tot };

	char* message = __concatenate_strings(items, 2);

	print_string(message);

	free_string(message);
	free_string(tot);
}

void print_start_end_internal(char* what_, const boolean is_start_, const boolean is_wrong_)
{
	char* what = (is_wrong_ ? __assign_string("wrong") : __string_to_upper(what_));
	char* separator = (is_start_ ? "--- " : " ---");

	char** items = __initialise_string_array(2);

	size_t i = 0;
	items = __update_string_array(items, (is_start_ ? separator : what), i);

	i++;
	items = __update_string_array(items, (is_start_ ? what : separator), i);

	size_t size = i + 1;

	char* message = __concatenate_strings(items, size);

	print_string(message);
	print_new_line();

	free_string(what);
	free_string(message);

	free_string_array(items, size);
}
