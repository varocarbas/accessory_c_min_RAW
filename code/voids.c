#include "headers/voids.h"

void* assign_void(void* out_, void* in_, const type type_) { return (void_type_is_ok(in_, type_) == TRUE ? assign(out_, in_, WRONG_SIZE, type_) : get_wrong_void_stack(type_)); }

void* __initialise_void(const type type_) { return __initialise(1, type_, FALSE); }

void* __assign_void(void* in_, const type type_) { return (void_type_is_ok(in_, type_) == TRUE ? __assign(in_, 1, type_, FALSE) : __get_wrong_void_heap(type_)); }

void* __assign_free_in_void(void* in_h_, const type type_) { return (void_type_is_ok(in_h_, type_) == TRUE ? __assign_free_in(in_h_, 1, type_, FALSE) : __assign_free_wrong_void(in_h_, type_)); }

void* __assign_free_out_void(void* out_h_, void* in_, const type type_) { return (void_type_is_ok(in_, type_) == TRUE ? __assign_free_out(out_h_, in_, 1, type_, FALSE) : __assign_free_wrong_void(out_h_, type_)); }

void* __assign_free_both_void(void* out_h_, void* in_h_, const type type_) { return (void_type_is_ok(in_h_, type_) == TRUE ? __assign_free_both(out_h_, in_h_, 1, type_, FALSE) : __assign_free_both_wrong_void(out_h_, in_h_, type_)); }

void* __assign_wrong_void(const type type_) { return __assign_wrong(0, type_, FALSE); }

void* __assign_free_wrong_void(void* in_out_h_, const type type_) { return __assign_free_wrong(in_out_h_, 0, type_, FALSE); }

void* __assign_free_both_wrong_void(void* out_h_, void* in_h_, const type type_) { return __assign_free_both_wrong(out_h_, in_h_, 0, type_, FALSE); }

void* get_wrong_void(const type type_) { return get_wrong_void_stack(type_); }

void* _get_wrong_void(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* get_wrong_void_stack(const type type_) { return get_wrong_stack(type_, FALSE); }

void* __get_wrong_void_heap(const type type_) {	return __get_wrong_heap(type_, FALSE); }

boolean void_is_ok(void* in_) { return pointer_is_ok(in_); }

boolean void_type_is_ok(void* in_, const type type_) { return ((void_is_ok(in_) == TRUE && ((type_ == STRING && string_is_ok(in_) == TRUE) || (type_ != STRING && in_ != get_wrong_void(type_)))) ? TRUE : FALSE); }

char* _void_to_string(void* in_, const type type_) { return (type_is_custom(type_) == TRUE ? _custom_void_to_string(in_, type_) : __native_void_to_string(in_, type_)); }

char* _custom_void_to_string(void* in_, const type type_)
{
	char* out;

	if (void_type_is_ok(in_, type_) == FALSE) out = _get_wrong_string(custom_void_to_string_is_heap(type_));
	else if (type_ == TYPE) out = type_to_string(void_to_type(in_));
	else if (type_ == ERROR) out = error_to_string(void_to_error(in_));
	else if (type_ == WARNING) out = warning_to_string(void_to_warning(in_));
	else if (type_ == ERROR_WARNING) out = error_warning_to_string(void_to_error_warning(in_));
	else if (type_ == OUTPUT) out = __output_to_string(void_to_output(in_));
	else if (type_ == BOOLEAN) out = boolean_to_string(void_to_boolean(in_));
	else out = _get_wrong_string(custom_void_to_string_is_heap(type_));

	return out;
}

char* __native_void_to_string(void* in_, const type type_)
{
	char* out;

	if (void_type_is_ok(in_, type_) == FALSE) out = __get_wrong_string_heap();
	else if (type_ == STRING) out = __assign_string(void_to_string(in_));
	else if (type_ == CHAR) out = __char_to_string(void_to_char(in_));
	else if (type_ == INT) out = __int_to_string(void_to_int(in_));
	else if (type_ == SIZE) out = __size_to_string(void_to_size(in_));
	else if (type_ == SHORT) out = __short_to_string(void_to_short(in_));
	else if (type_ == LONG) out = __long_to_string(void_to_long(in_));
	else if (type_ == DOUBLE) out = __double_to_string(void_to_double(in_));
	else out = __get_wrong_string_heap();

	return out;
}

boolean void_to_string_is_heap(const type type_) { return (type_is_custom(type_) == TRUE ? custom_void_to_string_is_heap(type_) : native_void_to_string_is_heap(type_)); }

boolean custom_void_to_string_is_heap(const type type_) { return type_is_pointer(type_); }

boolean native_void_to_string_is_heap(const type type_) { return TRUE; }

char* __concatenate_two_voids(void* in1_, const type type1_, void* in2_, const type type2_)
{
	char* in1 = _void_to_string(in1_, type1_);
	char* in2 = _void_to_string(in2_, type2_);

	size_t length1 = get_string_length_internal(in1, FALSE);
	size_t length2 = get_string_length_internal(in2, FALSE);

	char* out = ((length1 > WRONG_SIZE && length2 > WRONG_SIZE) ? __concatenate_two_strings_internal(in1, length1, in2, length2) : __get_wrong_string_heap());

	if (void_to_string_is_heap(type1_)) free_string(in1);
	if (void_to_string_is_heap(type2_)) free_string(in2);

	return out;
}

type void_to_type(void* in_) { return (void_is_ok(in_) == TRUE ? *((type*)in_) : WRONG_TYPE); }

type_error void_to_error(void* in_) { return (void_is_ok(in_) == TRUE ? *((type_error*)in_) : WRONG_ERROR); }

type_warning void_to_warning(void* in_) { return (void_is_ok(in_) == TRUE ? *((type_warning*)in_) : WRONG_WARNING); }

error_warning* void_to_error_warning(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_ERROR_WARNING); }

output* void_to_output(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_OUTPUT); }

boolean void_to_boolean(void* in_) { return (void_is_ok(in_) == TRUE ? *((boolean*)in_) : WRONG_BOOLEAN); }

char* void_to_string(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_STRING); }

char void_to_char(void* in_) { return (void_is_ok(in_) == TRUE ? *((char*)in_) : WRONG_CHAR); }

int void_to_int(void* in_) { return (void_is_ok(in_) == TRUE ? *((int*)in_) : WRONG_INT); }

size_t void_to_size(void* in_) { return (void_is_ok(in_) == TRUE ? *((size_t*)in_) : WRONG_SIZE); }

short void_to_short(void* in_) { return (void_is_ok(in_) == TRUE ? *((short*)in_) : WRONG_SHORT); }

long void_to_long(void* in_) { return (void_is_ok(in_) == TRUE ? *((long*)in_) : WRONG_LONG); }

double void_to_double(void* in_) { return (void_is_ok(in_) == TRUE ? *((double*)in_) : WRONG_DOUBLE); }

type* void_to_type_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

type_error* void_to_error_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

type_warning* void_to_warning_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

error_warning** void_to_error_warning_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

output** void_to_output_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

boolean* void_to_boolean_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

char** void_to_string_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

char* void_to_char_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

int* void_to_int_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

size_t* void_to_size_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

short* void_to_short_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

long* void_to_long_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

double* void_to_double_array(void* in_) { return (void_is_ok(in_) == TRUE ? in_ : WRONG_POINTER); }

void* update_void_value(void* out_, void* value_, const type type_)
{
	if (type_ == TYPE) *((type*)out_) = void_to_type(value_);
	else if (type_ == ERROR) *((type_error*)out_) = void_to_error(value_);
	else if (type_ == WARNING) *((type_warning*)out_) = void_to_warning(value_);
	else if (type_ == ERROR_WARNING) *((error_warning*)out_) = *void_to_error_warning(value_);
	else if (type_ == OUTPUT) *((output*)out_) = *void_to_output(value_);
	else if (type_ == BOOLEAN) *((boolean*)out_) = void_to_boolean(value_);
	else if (type_ == STRING) *((char*)out_) = *void_to_string(value_);
	else if (type_ == CHAR) *((char*)out_) = void_to_char(value_);
	else if (type_ == INT) *((int*)out_) = void_to_int(value_);
	else if (type_ == SIZE) *((size_t*)out_) = void_to_size(value_);
	else if (type_ == SHORT) *((short*)out_) = void_to_short(value_);
	else if (type_ == LONG) *((long*)out_) = void_to_long(value_);
	else if (type_ == DOUBLE) *((double*)out_) = void_to_double(value_);

	return out_;
}

void* __type_to_void(const type in_)
{
	type* out;

	type type0 = TYPE;

	if (in_ != WRONG_TYPE)
	{
		out = __initialise_void(type0);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type0);

	return out;
}

void* __error_to_void(const type_error in_)
{
	type_error* out;

	type type = ERROR;

	if (in_ != WRONG_ERROR)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __warning_to_void(const type_warning in_)
{
	type_warning* out;

	type type = WARNING;

	if (in_ != WRONG_WARNING)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* error_warning_to_void(error_warning* in_) { return error_warning_pointer_to_void(in_); }

void* output_to_void(output* in_) { return output_pointer_to_void(in_); }

void* __boolean_to_void(const boolean in_)
{
	boolean* out;

	type type = BOOLEAN;

	if (in_ != WRONG_BOOLEAN)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* string_to_void(char* in_) { return string_pointer_to_void(in_); }

void* __char_to_void(const char in_)
{
	char* out;

	type type = CHAR;

	if (in_ != WRONG_CHAR)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __int_to_void(const int in_)
{
	int* out;

	type type = INT;

	if (in_ != WRONG_INT)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __size_to_void(const size_t in_)
{
	size_t* out;

	type type = SIZE;

	if (in_ != WRONG_SIZE)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __short_to_void(const short in_)
{
	short* out;

	type type = SHORT;

	if (in_ != WRONG_SHORT)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __long_to_void(const long in_)
{
	long* out;

	type type = LONG;

	if (in_ != WRONG_LONG)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* __double_to_void(const double in_)
{
	double* out;

	type type = DOUBLE;

	if (in_ != WRONG_DOUBLE)
	{
		out = __initialise_void(type);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void_heap(type);

	return out;
}

void* array_to_void(void* in_) { return in_; }

void* pointer_to_void(void* in_, type type_)
{
	void* out;

	if (void_type_is_ok(in_, type_) == FALSE) out = WRONG_POINTER;
	else if (type_ == TYPE) out = type_pointer_to_void(in_);
	else if (type_ == ERROR) out = error_pointer_to_void(in_);
	else if (type_ == WARNING) out = warning_pointer_to_void(in_);
	else if (type_ == ERROR_WARNING) out = error_warning_pointer_to_void(in_);
	else if (type_ == OUTPUT) out = output_pointer_to_void(in_);
	else if (type_ == BOOLEAN) out = boolean_pointer_to_void(in_);
	else if (type_ == STRING) out = string_pointer_to_void(in_);
	else if (type_ == CHAR) out = char_pointer_to_void(in_);
	else if (type_ == INT) out = int_pointer_to_void(in_);
	else if (type_ == SIZE) out = size_pointer_to_void(in_);
	else if (type_ == SHORT) out = short_pointer_to_void(in_);
	else if (type_ == LONG) out = long_pointer_to_void(in_);
	else if (type_ == DOUBLE) out = double_pointer_to_void(in_);
	else out = WRONG_POINTER;

	return out;
}

void* type_pointer_to_void(type* in_) { return (void_type_is_ok(in_, TYPE) == TRUE ? in_ : WRONG_POINTER); }

void* error_pointer_to_void(type_error* in_) { return (void_type_is_ok(in_, ERROR) == TRUE ? in_ : WRONG_POINTER); }

void* warning_pointer_to_void(type_warning* in_) { return (void_type_is_ok(in_, WARNING) == TRUE ? in_ : WRONG_POINTER); }

void* error_warning_pointer_to_void(error_warning* in_) { return (void_type_is_ok(in_, ERROR_WARNING) == TRUE ? in_ : WRONG_POINTER); }

void* output_pointer_to_void(output* in_) { return (void_type_is_ok(in_, OUTPUT) == TRUE ? in_ : WRONG_POINTER); }

void* boolean_pointer_to_void(boolean* in_) { return (void_type_is_ok(in_, BOOLEAN) == TRUE ? in_ : WRONG_POINTER); }

void* string_pointer_to_void(char* in_) { return (void_type_is_ok(in_, STRING) == TRUE ? in_ : WRONG_POINTER); }

void* char_pointer_to_void(char* in_) { return (void_type_is_ok(in_, CHAR) == TRUE ? in_ : WRONG_POINTER); }

void* int_pointer_to_void(int* in_) { return (void_type_is_ok(in_, INT) == TRUE ? in_ : WRONG_POINTER); }

void* size_pointer_to_void(size_t* in_) { return (void_type_is_ok(in_, SIZE) == TRUE ? in_ : WRONG_POINTER); }

void* short_pointer_to_void(short* in_) { return (void_type_is_ok(in_, SHORT) == TRUE ? in_ : WRONG_POINTER); }

void* long_pointer_to_void(long* in_) { return (void_type_is_ok(in_, LONG) == TRUE ? in_ : WRONG_POINTER); }

void* double_pointer_to_void(double* in_) { return (void_type_is_ok(in_, DOUBLE) == TRUE ? in_ : WRONG_POINTER); }
