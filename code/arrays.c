#include "headers/arrays.h"

void* assign_array(void* out_, void* in_, const size_t size_, const type type_)
{
	if (array_is_ok(in_, size_, type_) == FALSE) out_ = assign(out_, get_wrong_array_stack(), type_, size_);
	else if (type_array_is_2d(type_) == TRUE) out_ = assign(out_, get_wrong_array_stack(), type_, size_);
	else out_ = assign(out_, in_, type_, size_);

	return out_;
}

void* __initialise_array(const size_t size_, const type type_) { return __initialise(size_, type_, TRUE); }

void* __assign_array(void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign_array_internal(WRONG_POINTER, in_, size_, type_, FALSE, FALSE) : __assign_wrong_array(size_, type_)); }

void* __assign_free_in_array(void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE? __assign_array_internal(WRONG_POINTER, in_h_, size_, type_, FALSE, TRUE) : __assign_free_wrong_array(in_h_, size_, type_)); }

void* __assign_free_out_array(void* out_h_, void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign_array_internal(out_h_, WRONG_POINTER, size_, type_, TRUE, FALSE) : __assign_free_wrong_array(out_h_, size_, type_)); }

void* __assign_free_both_array(void* out_h_, void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE ? __assign_array_internal(out_h_, in_h_, size_, type_, TRUE, TRUE) : __assign_free_both_wrong_array(out_h_, in_h_, size_, type_)); }

void* __assign_wrong_array() { return __assign_wrong_array_internal(WRONG_POINTER, WRONG_POINTER, WRONG_SIZE, WRONG_TYPE, FALSE, FALSE); }

void* __assign_free_wrong_array(void* in_out_h_, const size_t size_, const type type_) { return __assign_wrong_array_internal(in_out_h_, WRONG_POINTER, size_, type_, TRUE, FALSE); }

void* __assign_free_both_wrong_array(void* out_h_, void* in_h_, const size_t size_, const type type_) { return __assign_wrong_array_internal(in_h_, out_h_, size_, type_, TRUE, TRUE); }

void free_array(void* in_h_, const size_t size_, const type type_)
{
	if (type_array_is_2d(type_) == TRUE) free_2d_array(in_h_, size_, type_);
	else free_(in_h_, type_);
}

void free_2d_array(void* in_h_, const size_t size_, const type type_)
{
	if (array_is_ok(in_h_, size_, type_) == TRUE)
	{
		for (size_t i = 0; i < size_; i++) { free_array_internal(in_h_, i, type_); }
	}

	free(in_h_);
}

void* _get_wrong_array(const boolean is_heap_) { return _get_wrong(WRONG_TYPE, TRUE, is_heap_); }

void* get_wrong_array_stack() { return get_wrong_stack(WRONG_TYPE, TRUE); }

void* __get_wrong_array_heap() { return __get_wrong_heap(WRONG_TYPE, TRUE); }

boolean array_is_ok(void* in_, const size_t size_, const type type_) { return (array_is_ok_internal(in_) == TRUE && size_ > WRONG_SIZE && type_ != WRONG_TYPE); }

size_t get_initial_array_size(const size_t size_, const type type_, const boolean is_heap_) { return get_memory_size(size_, type_, is_heap_); }

void* __reduce_array_size(void* in_, const size_t size_, const type type_, const boolean free_in_)
{
	void* out = __initialise_array(size_, type_);

	boolean is_2d = type_array_is_2d(type_);

	for (size_t i = 0; i < size_; i++)
	{
		void* value = get_array_value(in_, i, type_);

		out = (is_2d == TRUE ? _add_update_2d_array_internal(out, value, i, type_, ADD) : add_update_1d_array_internal(out, value, i, type_, ADD));
	}

	if (free_in_ == TRUE) free_array(in_, size_, type_);

	return out;
}

void* get_array_value(void* in_, const size_t i_, const type type_)
{
	void* out;

	if (void_type_is_ok(in_, type_) == FALSE) out = get_wrong_array_stack();
	else if (type_ == TYPE) out = &void_to_type_array(in_)[i_];
	else if (type_ == ERROR) out = &void_to_error_array(in_)[i_];
	else if (type_ == WARNING) out = &void_to_warning_array(in_)[i_];
	else if (type_ == ERROR_WARNING) out = void_to_error_warning_array(in_)[i_];
	else if (type_ == OUTPUT) out = void_to_output_array(in_)[i_];
	else if (type_ == BOOLEAN) out = &void_to_boolean_array(in_)[i_];
	else if (type_ == STRING) out = void_to_string_array(in_)[i_];
	else if (type_ == CHAR) out = &void_to_char_array(in_)[i_];
	else if (type_ == INT) out = &void_to_int_array(in_)[i_];
	else if (type_ == SIZE) out = &void_to_size_array(in_)[i_];
	else if (type_ == SHORT) out = &void_to_short_array(in_)[i_];
	else if (type_ == LONG) out = &void_to_long_array(in_)[i_];
	else if (type_ == DOUBLE) out = &void_to_double_array(in_)[i_];
	else out = get_wrong_void(type_);

	return out;
}

type get_array_type_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_type(get_array_value(in_, i_, TYPE)) : WRONG_TYPE); }

type_error get_array_error_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_error(get_array_value(in_, i_, ERROR)) : WRONG_ERROR); }

type_warning get_array_warning_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_warning(get_array_value(in_, i_, WARNING)) : WRONG_WARNING); }

error_warning* get_array_error_warning_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_error_warning(get_array_value(in_, i_, ERROR_WARNING)) : WRONG_ERROR_WARNING); }

output* get_array_output_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_output(get_array_value(in_, i_, OUTPUT)) : WRONG_OUTPUT); }

boolean get_array_boolean_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_boolean(get_array_value(in_, i_, BOOLEAN)) : WRONG_BOOLEAN); }

char* get_array_string_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_string(get_array_value(in_, i_, STRING)) : WRONG_STRING); }

char get_array_char_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_char(get_array_value(in_, i_, CHAR)) : WRONG_CHAR); }

int get_array_int_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_int(get_array_value(in_, i_, INT)) : WRONG_INT); }

size_t get_array_size_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_size(get_array_value(in_, i_, SIZE)) : WRONG_SIZE); }

short get_array_short_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_short(get_array_value(in_, i_, SHORT)) : WRONG_SHORT); }

long get_array_long_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_long(get_array_value(in_, i_, LONG)) : WRONG_LONG); }

double get_array_double_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_double(get_array_value(in_, i_, DOUBLE)) : WRONG_DOUBLE); }

void* _add_to_array(void* array_, void* value_, const size_t i_, const type type_) { return ((type_array_is_2d(type_) == TRUE) ? __add_to_2d_array(array_, value_, i_, type_) : add_to_1d_array(array_, value_, i_, type_)); }

void* update_array(void* array_, void* value_, const size_t i_, const type type_) { return ((type_array_is_2d(type_) == TRUE) ? update_2d_array(array_, value_, i_, type_) : update_1d_array(array_, value_, i_, type_)); }

void* add_to_1d_array(void* array_, void* value_, const size_t i_, const type type_) { return (array_is_ok_internal(array_) == TRUE ? add_update_1d_array_internal(array_, value_, i_, type_, ADD) : array_); }

void* update_1d_array(void* array_, void* value_, const size_t i_, const type type_) { return (array_is_ok_internal(array_) == TRUE ? add_update_1d_array_internal(array_, value_, i_, type_, UPDATE) : array_); }

void* __add_to_2d_array(void* array_, void* value_, const size_t i_, const type type_) { return (array_is_ok_internal(array_) == TRUE ? _add_update_2d_array_internal(array_, value_, i_, type_, ADD) : array_); }

void* update_2d_array(void* array_, void* value_, const size_t i_, const type type_) { return (array_is_ok_internal(array_) == TRUE ? _add_update_2d_array_internal(array_, value_, i_, type_, UPDATE) : array_); }

void print_array(void* in_, const size_t size_, const type type_) { _print_array_to_string_internal(in_, size_, type_, TRUE); }

char* __array_to_string(void* in_, const size_t size_, const type type_) { return _print_array_to_string_internal(in_, size_, type_, FALSE); }

char* _print_array_to_string_internal(void* in_, const size_t size_, const type type_, const boolean is_print_)
{
	if (array_is_ok(in_, size_, type_) == FALSE) return (is_print_ == TRUE ? WRONG_POINTER : __get_wrong_string_heap());

	char* out = WRONG_POINTER;

	if (is_print_ == TRUE) print_array_start_end_internal(TRUE);

	const size_t max_i = size_ - 1;

	for (size_t i = 0; i <= max_i; i++)
	{
		void* temp;

		if (type_ == ERROR_WARNING) temp = void_to_error_warning_array(in_)[i];
		else if (type_ == OUTPUT) temp = void_to_output_array(in_)[i];
		else if (type_ == STRING) temp = void_to_string_array(in_)[i];
		else temp = get_array_value(in_, i, type_);

		if (is_print_ == TRUE) print_array_item_internal(i, max_i, temp, get_type_format(type_), type_);
		else return __get_wrong_string_heap();
	}

	if (is_print_ == TRUE) print_array_start_end_internal(FALSE);

	return out;
}

boolean array_is_ok_internal(void* in_) { return pointer_is_ok(in_); }

void* __assign_array_internal(void* out_, void* in_, const size_t size_, const type type_, const boolean free_out_, const boolean free_in_)
{
	if (free_out_) free_array(out_, size_, type_);

	if (array_is_ok(in_, size_, type_) == FALSE)
	{
		if (free_in_) free_array(in_, size_, type_);

		out_ = __assign_wrong_array(size_, type_);
	}
	else if (type_array_is_2d(type_) == TRUE)
	{
		out_ = __assign_wrong_array(size_, type_);
	}
	else out_ = __assign(in_, size_, type_, TRUE);

	if (free_in_) free_array(in_, size_, type_);

	return out_;
}

void* __assign_wrong_array_internal(void* out_, void* in_, const size_t size_, const type type_, const boolean free_out_, const boolean free_in_)
{
	if (free_out_) free_array(out_, size_, type_);
	if (free_in_) free_array(in_, size_, type_);

	return __assign_wrong_array(size_, type_);
}

void free_array_internal(void* in_h_, const size_t i_, const type type_) { free_(get_array_value(in_h_, i_, type_), type_); }

void* add_update_1d_array_internal(void* array_, void* value_, const size_t i_, const type type_, const action action_)
{
	void* temp = get_array_value(array_, i_, type_);

	if (type_ == TYPE) ((type*)array_)[i_] = void_to_type(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == ERROR) ((type_error*)array_)[i_] = void_to_error(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == WARNING) ((type_warning*)array_)[i_] = void_to_warning(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == BOOLEAN) ((boolean*)array_)[i_] = void_to_boolean(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == CHAR) ((char*)array_)[i_] = void_to_char(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == INT) ((int*)array_)[i_] = void_to_int(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == SIZE) ((size_t*)array_)[i_] = void_to_size(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == SHORT) ((short*)array_)[i_] = void_to_short(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == LONG) ((long*)array_)[i_] = void_to_long(action_ == ADD ? value_ : update_void_value(temp, value_, type_));
	else if (type_ == DOUBLE) ((double*)array_)[i_] = void_to_double(action_ == ADD ? value_ : update_void_value(temp, value_, type_));

	return array_;
}

void* _add_update_2d_array_internal(void* array_, void* value_, const size_t i_, const type type_, const action action_)
{
	void* temp = get_array_value(array_, i_, type_);

	if (type_ == ERROR_WARNING) ((error_warning**)array_)[i_] = void_to_error_warning(action_ == ADD ? __assign_void(value_, type_) : update_void_value(temp, value_, type_));
	else if (type_ == OUTPUT) ((output**)array_)[i_] = void_to_output(action_ == ADD ? __assign_void(value_, type_) : update_void_value(temp, value_, type_));
	else if (type_ == STRING) ((char**)array_)[i_] = void_to_string(action_ == ADD ? __assign_void(value_, type_) : update_void_value(temp, value_, type_));

	return array_;
}

void print_array_start_end_internal(const boolean is_start_)
{
	print_string_internal((is_start_ == TRUE ? DEFAULT_SEPARATOR_START : DEFAULT_SEPARATOR_END), FALSE);

	if (is_start_ == FALSE) print_new_line();
}

void print_array_item_internal(const size_t i, const size_t max_i, void* variable_, char* format_, const type type_)
{
	print_internal(variable_, format_, type_, FALSE);

	if (i < max_i) print_string_internal(DEFAULT_SEPARATOR_ITEMS, FALSE);
}
