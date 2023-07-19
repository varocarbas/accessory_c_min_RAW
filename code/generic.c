#include "headers/generic.h"

void* get_wrong_generic(const type type_) { return get_wrong_generic_stack(type_); }

void* _get_wrong_generic(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* get_wrong_generic_stack(const type type_) { return get_wrong_stack(type_, FALSE); }

void* __get_wrong_generic_heap(const type type_) { return __get_wrong_heap(type_, FALSE); }

void* _get_wrong_generic_array(const type type_, const boolean is_heap_) { return _get_wrong(type_, TRUE, is_heap_); }

void* get_wrong_generic_array_stack(const type type_) { return get_wrong_stack(type_, TRUE); }

void* __get_wrong_generic_array_heap(const type type_) { return __get_wrong_heap(type_, TRUE); }

type generic_to_type(void* in_) { return (in_ != WRONG_POINTER ? *((type*)in_) : WRONG_TYPE); }

type_error generic_to_error(void* in_) { return (in_ != WRONG_POINTER ? *((type_error*)in_) : WRONG_ERROR); }

type_warning generic_to_warning(void* in_) { return (in_ != WRONG_POINTER ? *((type_warning*)in_) : WRONG_WARNING); }

error_warning* generic_to_error_warning(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_ERROR_WARNING); }

output* generic_to_output(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_OUTPUT); }

boolean generic_to_boolean(void* in_) { return (in_ != WRONG_POINTER ? *((boolean*)in_) : WRONG_BOOLEAN); }

char* generic_to_string(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_STRING); }

char generic_to_char(void* in_) { return (in_ != WRONG_POINTER ? *((char*)in_) : WRONG_CHAR); }

int generic_to_int(void* in_) { return (in_ != WRONG_POINTER ? *((int*)in_) : WRONG_INT); }

size_t generic_to_size(void* in_) { return (in_ != WRONG_POINTER ? *((size_t*)in_) : WRONG_SIZE); }

short generic_to_short(void* in_) { return (in_ != WRONG_POINTER ? *((short*)in_) : WRONG_SHORT); }

long generic_to_long(void* in_) { return (in_ != WRONG_POINTER ? *((long*)in_) : WRONG_LONG); }

double generic_to_double(void* in_) { return (in_ != WRONG_POINTER ? *((double*)in_) : WRONG_DOUBLE); }

type* generic_to_type_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

type_error* generic_to_error_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

type_warning* generic_to_warning_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

error_warning** generic_to_error_warning_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

output** generic_to_output_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

boolean* generic_to_boolean_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

char** generic_to_string_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

char* generic_to_char_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

int* generic_to_int_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

size_t* generic_to_size_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

short* generic_to_short_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

long* generic_to_long_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

double* generic_to_double_array(void* in_) { return (in_ != WRONG_POINTER ? in_ : WRONG_POINTER); }

type get_generic_array_type(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_type(get_generic_array_generic(in_, i_, TYPE)): WRONG_TYPE); }

type_error get_generic_array_error(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_error(get_generic_array_generic(in_, i_, ERROR)): WRONG_ERROR); }

type_warning get_generic_array_warning(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_warning(get_generic_array_generic(in_, i_, WARNING)): WRONG_WARNING); }

error_warning* get_generic_array_error_warning(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_error_warning(get_generic_array_generic(in_, i_, ERROR_WARNING)): WRONG_ERROR_WARNING); }

output* get_generic_array_output(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_output(get_generic_array_generic(in_, i_, OUTPUT)): WRONG_OUTPUT); }

boolean get_generic_array_boolean(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_boolean(get_generic_array_generic(in_, i_, BOOLEAN)): WRONG_BOOLEAN); }

char* get_generic_array_string(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_string(get_generic_array_generic(in_, i_, STRING)): WRONG_STRING); }

char get_generic_array_char(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_char(get_generic_array_generic(in_, i_, CHAR)): WRONG_CHAR); }

int get_generic_array_int(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_int(get_generic_array_generic(in_, i_, INT)): WRONG_INT); }

size_t get_generic_array_size(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_size(get_generic_array_generic(in_, i_, SIZE)): WRONG_SIZE); }

short get_generic_array_short(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_short(get_generic_array_generic(in_, i_, SHORT)): WRONG_SHORT); }

long get_generic_array_long(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_long(get_generic_array_generic(in_, i_, LONG)): WRONG_LONG); }

double get_generic_array_double(void* in_, const size_t i_) { return (in_ != WRONG_POINTER ? generic_to_double(get_generic_array_generic(in_, i_, DOUBLE)): WRONG_DOUBLE); }

void* get_generic_array_generic(void* in_, const size_t i_, const type type_)
{
	if (in_ == WRONG_POINTER || type_ == WRONG_TYPE) return get_wrong_generic(type_);

	void* out;

	if (type_ == TYPE) out = &generic_to_type_array(in_)[i_];
	else if (type_ == ERROR) out = &generic_to_error_array(in_)[i_];
	else if (type_ == WARNING) out = &generic_to_warning_array(in_)[i_];
	else if (type_ == ERROR_WARNING) out = generic_to_error_warning_array(in_)[i_];
	else if (type_ == OUTPUT) out = generic_to_output_array(in_)[i_];
	else if (type_ == BOOLEAN) out = &generic_to_boolean_array(in_)[i_];
	else if (type_ == STRING) out = generic_to_string_array(in_)[i_];
	else if (type_ == CHAR) out = &generic_to_char_array(in_)[i_];
	else if (type_ == INT) out = &generic_to_int_array(in_)[i_];
	else if (type_ == SIZE) out = &generic_to_size_array(in_)[i_];
	else if (type_ == SHORT) out = &generic_to_short_array(in_)[i_];
	else if (type_ == LONG) out = &generic_to_long_array(in_)[i_];
	else if (type_ == DOUBLE) out = &generic_to_double_array(in_)[i_];

	return out;
}

void* __type_to_generic(const type in_)
{
	type* out;

	type type0 = TYPE;

	if (in_ != WRONG_TYPE)
	{
		out = __initialise_variable(type0);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type0);

	return out;
}

void* __error_to_generic(const type_error in_)
{
	type_error* out;

	type type = ERROR;

	if (in_ != WRONG_ERROR)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __warning_to_generic(const type_warning in_)
{
	type_warning* out;

	type type = WARNING;

	if (in_ != WRONG_WARNING)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* error_warning_to_generic(error_warning* in_) { return error_warning_pointer_to_generic(in_); }

void* output_to_generic(output* in_) { return output_pointer_to_generic(in_); }

void* __boolean_to_generic(const boolean in_)
{
	boolean* out;

	type type = BOOLEAN;

	if (in_ != WRONG_BOOLEAN)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* string_to_generic(char* in_) { return string_pointer_to_generic(in_); }

void* __char_to_generic(const char in_)
{
	char* out;

	type type = CHAR;

	if (in_ != WRONG_CHAR)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __int_to_generic(const int in_)
{
	int* out;

	type type = INT;

	if (in_ != WRONG_INT)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __size_to_generic(const size_t in_)
{
	size_t* out;

	type type = SIZE;

	if (in_ != WRONG_SIZE)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __short_to_generic(const short in_)
{
	short* out;

	type type = SHORT;

	if (in_ != WRONG_SHORT)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __long_to_generic(const long in_)
{
	long* out;

	type type = LONG;

	if (in_ != WRONG_LONG)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* __double_to_generic(const double in_)
{
	double* out;

	type type = DOUBLE;

	if (in_ != WRONG_DOUBLE)
	{
		out = __initialise_variable(type);

		*out = in_;
	}
	else out = __get_wrong_generic_heap(type);

	return out;
}

void* pointer_to_generic(void* in_, type type_)
{
	void* out;

	if (type_ == TYPE) out = type_pointer_to_generic(in_);
	else if (type_ == ERROR) out = error_pointer_to_generic(in_);
	else if (type_ == WARNING) out = warning_pointer_to_generic(in_);
	else if (type_ == ERROR_WARNING) out = error_warning_pointer_to_generic(in_);
	else if (type_ == OUTPUT) out = output_pointer_to_generic(in_);
	else if (type_ == BOOLEAN) out = boolean_pointer_to_generic(in_);
	else if (type_ == STRING) out = string_pointer_to_generic(in_);
	else if (type_ == CHAR) out = char_pointer_to_generic(in_);
	else if (type_ == INT) out = int_pointer_to_generic(in_);
	else if (type_ == SIZE) out = size_pointer_to_generic(in_);
	else if (type_ == SHORT) out = short_pointer_to_generic(in_);
	else if (type_ == LONG) out = long_pointer_to_generic(in_);
	else if (type_ == DOUBLE) out = double_pointer_to_generic(in_);
	else out = WRONG_POINTER;

	return out;
}

void* type_pointer_to_generic(type* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_TYPE) ? in_ : WRONG_POINTER); }

void* error_pointer_to_generic(type_error* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_ERROR) ? in_ : WRONG_POINTER); }

void* warning_pointer_to_generic(type_warning* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_WARNING) ? in_ : WRONG_POINTER); }

void* error_warning_pointer_to_generic(error_warning* in_) { return ((in_ != WRONG_POINTER && in_ != WRONG_ERROR_WARNING) ? in_ : WRONG_POINTER); }

void* output_pointer_to_generic(output* in_) { return ((in_ != WRONG_POINTER && in_ != WRONG_OUTPUT) ? in_ : WRONG_POINTER); }

void* boolean_pointer_to_generic(boolean* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_BOOLEAN) ? in_ : WRONG_POINTER); }

void* string_pointer_to_generic(char* in_) { return ((in_ != WRONG_POINTER && strings_are_equal(in_, WRONG_STRING) == FALSE) ? in_ : WRONG_POINTER); }

void* char_pointer_to_generic(char* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_CHAR) ? in_ : WRONG_POINTER); }

void* int_pointer_to_generic(int* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_INT) ? in_ : WRONG_POINTER); }

void* size_pointer_to_generic(size_t* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_SIZE) ? in_ : WRONG_POINTER); }

void* short_pointer_to_generic(short* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_SHORT) ? in_ : WRONG_POINTER); }

void* long_pointer_to_generic(long* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_LONG) ? in_ : WRONG_POINTER); }

void* double_pointer_to_generic(double* in_) { return ((in_ != WRONG_POINTER && *in_ != WRONG_DOUBLE) ? in_ : WRONG_POINTER); }
