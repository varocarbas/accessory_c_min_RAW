#include "headers/voids.h"

void* __initialise_void(const type type_) { return (type_ == STRING ? __get_wrong_string() : __initialise(1, type_, FALSE)); }

void* __assign_void(void* in_, const type type_)
{
	void* out;

	if (type_ == STRING) out = __assign_string(in_);
	else out = (void_is_ok(in_) == TRUE ? __assign(in_, 1, type_, FALSE) : __get_wrong_void(type_));

	return out;
}

void* __assign_free_in_void(void* in_h_, const type type_)
{
	void* out;

	if (type_ == STRING) out = __assign_free_in_string(in_h_);
	else out = (void_is_ok(in_h_) == TRUE ? __assign_free_in(in_h_, 1, type_, FALSE) : __get_wrong_void_free(in_h_, type_));

	return out;
}

void* __assign_free_out_void(void* out_h_, void* in_, const type type_)
{
	void* out;

	if (type_ == STRING) out = __assign_free_out_string(out_h_, in_);
	else out = (void_is_ok(in_) == TRUE ? __assign_free_out(out_h_, in_, 1, type_, FALSE) : __get_wrong_void_free(out_h_, type_));

	return out;
}

void* __assign_free_both_void(void* out_h_, void* in_h_, const type type_)
{
	void* out;

	if (type_ == STRING) out = __assign_free_both_string(out_h_, in_h_);
	else out = (void_is_ok(in_h_) == TRUE ? __assign_free_both(out_h_, in_h_, 1, type_, FALSE) : __get_wrong_void_free_both(out_h_, in_h_, type_));

	return out;
}

void free_void(void* in_h_, const type type_) { free_internal(in_h_, type_, FALSE); }

void* _get_wrong_void(const type type_, const boolean is_heap_) { return _get_wrong(type_, FALSE, is_heap_); }

void* get_wrong_void(const type type_) { return get_wrong(type_, FALSE); }

void* __get_wrong_void(const type type_) {	return __get_wrong(type_, FALSE); }

void* __get_wrong_void_free(void* in_out_h_, const type type_) { return (type_ == STRING ? __get_wrong_string_free(in_out_h_) : __get_wrong_free(in_out_h_, 0, type_)); }

void* __get_wrong_void_free_both(void* out_h_, void* in_h_, const type type_) { return (type_ == STRING ? __get_wrong_string_free_both(out_h_, in_h_) : __get_wrong_free_both(out_h_, in_h_, 0, type_)); }

boolean void_is_ok(void* in_) { return pointer_is_ok(in_); }

boolean void_type_is_ok(void* in_, const type type_) { return ((void_is_ok(in_) == TRUE && ((type_ == STRING && string_is_ok(in_) == TRUE) || (type_ != STRING && in_ != get_wrong_void(type_)))) ? TRUE : FALSE); }

boolean voids_are_equal(void* in1_, void* in2_, const type type_)
{
	boolean out = FALSE;

	boolean is_ok1 = void_type_is_ok(in1_, type_);
	boolean is_ok2 = void_type_is_ok(in2_, type_);

	if (is_ok1 == FALSE || is_ok2 == FALSE) out = (is_ok1 == is_ok2 ? TRUE : FALSE);
	else if (type_ == TYPE)
	{
		if (void_to_type(in1_) == void_to_type(in2_)) out = TRUE;
	}
	else if (type_ == ERROR)
	{
		if (void_to_error(in1_) == void_to_error(in2_)) out = TRUE;
	}
	else if (type_ == WARNING)
	{
		if (void_to_warning(in1_) == void_to_warning(in2_)) out = TRUE;
	}
	else if (type_ == ERROR_WARNING) out = error_warnings_are_equal(void_to_error_warning(in1_), void_to_error_warning(in2_));
	else if (type_ == OUTPUT) out = outputs_are_equal(void_to_output(in1_), void_to_output(in2_));
	else if (type_ == BOOLEAN)
	{
		if (void_to_boolean(in1_) == void_to_boolean(in2_)) out = TRUE;
	}
	else if (type_ == STRING) out = strings_are_equal(void_to_string(in1_), void_to_string(in2_));
	else if (type_ == CHAR)
	{
		if (void_to_char(in1_) == void_to_char(in2_)) out = TRUE;
	}
	else if (type_ == INT)
	{
		if (void_to_int(in1_) == void_to_int(in2_)) out = TRUE;
	}
	else if (type_ == SIZE)
	{
		if (void_to_size(in1_) == void_to_size(in2_)) out = TRUE;
	}
	else if (type_ == SHORT)
	{
		if (void_to_short(in1_) == void_to_short(in2_)) out = TRUE;
	}
	else if (type_ == LONG)
	{
		if (void_to_long(in1_) == void_to_long(in2_)) out = TRUE;
	}
	else if (type_ == DOUBLE)
	{
		if (void_to_double(in1_) == void_to_double(in2_)) out = TRUE;
	}

	return out;
}

char* _void_type_to_string(void* in_, const type type_) { return (type_is_custom(type_) == TRUE ? _custom_void_type_to_string(in_, type_) : __native_void_type_to_string(in_, type_)); }

char* _custom_void_type_to_string(void* in_, const type type_)
{
	char* out;

	if (void_is_ok(in_) == FALSE) out = _get_wrong_string(custom_void_type_to_string_is_heap(type_));
	else if (type_ == TYPE) out = type_to_string(void_to_type(in_));
	else if (type_ == ERROR) out = error_to_string(void_to_error(in_));
	else if (type_ == WARNING) out = warning_to_string(void_to_warning(in_));
	else if (type_ == ERROR_WARNING) out = __error_warning_to_string(void_to_error_warning(in_));
	else if (type_ == OUTPUT) out = __output_to_string(void_to_output(in_));
	else if (type_ == BOOLEAN) out = boolean_to_string(void_to_boolean(in_));
	else out = _get_wrong_string(custom_void_type_to_string_is_heap(type_));

	return out;
}

char* __native_void_type_to_string(void* in_, const type type_)
{
	char* out;

	if (void_is_ok(in_) == FALSE) out = __get_wrong_string();
	else if (type_ == STRING) out = __assign_string(void_to_string(in_));
	else if (type_ == CHAR) out = __char_to_string(void_to_char(in_));
	else if (type_ == INT) out = __int_to_string(void_to_int(in_));
	else if (type_ == SIZE) out = __size_to_string(void_to_size(in_));
	else if (type_ == SHORT) out = __short_to_string(void_to_short(in_));
	else if (type_ == LONG) out = __long_to_string(void_to_long(in_));
	else if (type_ == DOUBLE) out = __double_to_string(void_to_double(in_));
	else out = __get_wrong_string();

	return out;
}

boolean void_type_to_string_is_heap(const type type_) { return (type_is_custom(type_) == TRUE ? custom_void_type_to_string_is_heap(type_) : native_void_type_to_string_is_heap(type_)); }

boolean custom_void_type_to_string_is_heap(const type type_) { return type_is_pointer(type_); }

boolean native_void_type_to_string_is_heap(const type type_) { return TRUE; }

char* __concatenate_two_voids(void* in1_, const type type1_, void* in2_, const type type2_)
{
	char* in1 = _void_type_to_string(in1_, type1_);
	char* in2 = _void_type_to_string(in2_, type2_);

	size_t length1 = get_string_length_internal(in1, FALSE);
	size_t length2 = get_string_length_internal(in2, FALSE);

	char* out = ((length1 > WRONG_SIZE && length2 > WRONG_SIZE) ? __concatenate_two_strings_internal(in1, length1, in2, length2) : __get_wrong_string());

	if (void_type_to_string_is_heap(type1_)) free_string(in1);
	if (void_type_to_string_is_heap(type2_)) free_string(in2);

	return out;
}

type void_to_type(void* in_) { return (void_is_ok(in_) == TRUE ? *((type*)in_) : WRONG_TYPE); }

type_error void_to_error(void* in_) { return (void_is_ok(in_) == TRUE ? *((type_error*)in_) : WRONG_ERROR); }

type_warning void_to_warning(void* in_) { return (void_is_ok(in_) == TRUE ? *((type_warning*)in_) : WRONG_WARNING); }

error_warning* void_to_error_warning(void* in_) { return in_; }

output* void_to_output(void* in_) { return in_; }

boolean void_to_boolean(void* in_) { return (void_is_ok(in_) == TRUE ? *((boolean*)in_) : WRONG_BOOLEAN); }

char* void_to_string(void* in_) { return in_; }

char void_to_char(void* in_) { return (void_is_ok(in_) == TRUE ? *((char*)in_) : WRONG_CHAR); }

int void_to_int(void* in_) { return (void_is_ok(in_) == TRUE ? *((int*)in_) : WRONG_INT); }

size_t void_to_size(void* in_) { return (void_is_ok(in_) == TRUE ? *((size_t*)in_) : WRONG_SIZE); }

short void_to_short(void* in_) { return (void_is_ok(in_) == TRUE ? *((short*)in_) : WRONG_SHORT); }

long void_to_long(void* in_) { return (void_is_ok(in_) == TRUE ? *((long*)in_) : WRONG_LONG); }

double void_to_double(void* in_) { return (void_is_ok(in_) == TRUE ? *((double*)in_) : WRONG_DOUBLE); }

type* void_to_type_array(void* in_) { return in_; }

type_error* void_to_error_array(void* in_) { return in_; }

type_warning* void_to_warning_array(void* in_) { return in_; }

error_warning** void_to_error_warning_array(void* in_) { return in_; }

output** void_to_output_array(void* in_) { return in_; }

boolean* void_to_boolean_array(void* in_) { return in_; }

char** void_to_string_array(void* in_) { return in_; }

char* void_to_char_array(void* in_) { return in_; }

int* void_to_int_array(void* in_) { return in_; }

size_t* void_to_size_array(void* in_) { return in_; }

short* void_to_short_array(void* in_) { return in_; }

long* void_to_long_array(void* in_) { return in_; }

double* void_to_double_array(void* in_) { return in_; }

void* _update_void(void* out_, void* value_, const type type_)
{
	if (void_is_ok(out_) == FALSE) return out_;

	if (type_ == TYPE) *((type*)out_) = void_to_type(value_);
	else if (type_ == ERROR) *((type_error*)out_) = void_to_error(value_);
	else if (type_ == WARNING) *((type_warning*)out_) = void_to_warning(value_);
	else if (type_ == ERROR_WARNING) out_ = __update_error_warning(void_to_error_warning(out_), void_to_error_warning(value_));
	else if (type_ == OUTPUT) out_ = __update_output(void_to_output(out_), void_to_output(value_));
	else if (type_ == BOOLEAN) *((boolean*)out_) = void_to_boolean(value_);
	else if (type_ == STRING) out_ = __update_string(void_to_string(out_), void_to_string(value_), FALSE);
	else if (type_ == CHAR) *((char*)out_) = void_to_char(value_);
	else if (type_ == INT) *((int*)out_) = void_to_int(value_);
	else if (type_ == SIZE) *((size_t*)out_) = void_to_size(value_);
	else if (type_ == SHORT) *((short*)out_) = void_to_short(value_);
	else if (type_ == LONG) *((long*)out_) = void_to_long(value_);
	else if (type_ == DOUBLE) *((double*)out_) = void_to_double(value_);

	return out_;
}

boolean update_void_is_heap(const type type_) { return ((type_ == STRING || type_is_struct(type_) == TRUE) ? TRUE : FALSE); }

void* __type_to_void(const type in_)
{
	type* out;

	type type0 = TYPE;

	if (in_ != WRONG_TYPE)
	{
		out = __initialise_void(type0);

		if (pointer_is_ok(out) == TRUE) *out = in_;
	}
	else out = __get_wrong_void(type0);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

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
	else out = __get_wrong_void(type);

	return out;
}

void* array_to_void(void* in_) { return in_; }

void* pointer_to_void(void* in_, const type type_)
{
	void* out;

	if (void_is_ok(in_) == FALSE) out = WRONG_POINTER;
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

void* type_pointer_to_void(type* in_) { return in_; }

void* error_pointer_to_void(type_error* in_) { return in_; }

void* warning_pointer_to_void(type_warning* in_) { return in_; }

void* error_warning_pointer_to_void(error_warning* in_) { return in_; }

void* output_pointer_to_void(output* in_) { return in_; }

void* boolean_pointer_to_void(boolean* in_) { return in_; }

void* string_pointer_to_void(char* in_) { return in_; }

void* char_pointer_to_void(char* in_) { return in_; }

void* int_pointer_to_void(int* in_) { return in_; }

void* size_pointer_to_void(size_t* in_) { return in_; }

void* short_pointer_to_void(short* in_) { return in_; }

void* long_pointer_to_void(long* in_) { return in_; }

void* double_pointer_to_void(double* in_) { return in_; }
