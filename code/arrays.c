#include "headers/arrays.h"

void* __initialise_array(const size_t size_, const type type_) { return ((size_ > WRONG_SIZE && type_ != WRONG_TYPE) ? __initialise_array_item(size_, type_, DEFAULT_ARRAYS_ITEM_SIZE) : __get_wrong_array_heap()); }

void* __initialise_array_item(const size_t size_, const type type_, const size_t size_item_) { return __initialise_array_items(size_, type_, WRONG_POINTER); }

void* __initialise_array_items(const size_t size_, const type type_, size_t* sizes_items_)
{
	if (size_ == WRONG_SIZE || type_ == WRONG_TYPE) return __get_wrong_array_heap();

	void* out = __initialise(size_, type_, TRUE);
	if (pointer_is_ok(out) == FALSE) return out;

	if (type_array_is_2d_pointer(type_) == TRUE)
	{
		if (array_is_ok(sizes_items_, size_, SIZE) == FALSE) out = __initialise_update_2d_pointer_array_internal(out, WRONG_POINTER, size_, type_, DEFAULT_ARRAYS_ITEM_SIZE, INITIALISE);
		else
		{
			for (size_t i = 0; i < size_; i++) { out = __initialise_2d_pointer_array_item_internal(out, i, type_, sizes_items_[i]); }
		}
	}

	return out;
}

void* __assign_array(void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign_array_internal(WRONG_POINTER, in_, size_, type_, WRONG_POINTER, FALSE, FALSE) : __get_wrong_array_heap()); }

void* __assign_free_in_array(void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE ? __assign_array_internal(WRONG_POINTER, in_h_, size_, type_, WRONG_POINTER, FALSE, TRUE) : __get_wrong_array_free(in_h_, size_, type_)); }

void* __assign_free_out_array(void* out_h_, void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign_array_internal(out_h_, WRONG_POINTER, size_, type_, WRONG_POINTER, TRUE, FALSE) : __get_wrong_array_free(out_h_, size_, type_)); }

void* __assign_free_both_array(void* out_h_, void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE ? __assign_array_internal(out_h_, in_h_, size_, type_, WRONG_POINTER, TRUE, TRUE) : __get_wrong_array_free_both(out_h_, in_h_, size_, type_)); }

void free_array(void* in_h_, const size_t size_, const type type_)
{
	if (type_array_is_2d_pointer(type_) == TRUE) free_2d_pointer(in_h_, size_, type_);
	else free_internal(in_h_, type_, FALSE);
}

void free_2d_pointer(void* in_h_, const size_t size_, const type type_)
{
	if (array_is_ok(in_h_, size_, type_) == TRUE)
	{
		for (size_t i = 0; i < size_; i++) { free_array_internal(in_h_, i, type_); }
	}

	free_internal(in_h_, type_, TRUE);
}

void* _get_wrong_array(const boolean is_heap_) { return _get_wrong(WRONG_TYPE, TRUE, is_heap_); }

void* get_wrong_array_stack() { return get_wrong_stack(WRONG_TYPE, TRUE); }

void* __get_wrong_array_heap() { return __get_wrong_heap(WRONG_TYPE, TRUE); }

void* __get_wrong_array_free(void* in_out_h_, const size_t size_, const type type_) { return __get_wrong_array_internal(in_out_h_, WRONG_POINTER, size_, type_, TRUE, FALSE); }

void* __get_wrong_array_free_both(void* out_h_, void* in_h_, const size_t size_, const type type_) { return __get_wrong_array_internal(in_h_, out_h_, size_, type_, TRUE, TRUE); }

boolean is_array(const size_t size_) { return (size_ > WRONG_SIZE ? TRUE : FALSE); }

boolean array_is_ok(void* in_, const size_t size_, const type type_) { return (array_is_ok_internal(in_) == TRUE && size_ > WRONG_SIZE && type_ != WRONG_TYPE); }

boolean arrays_are_equal(void* in1_, const size_t size1_, void* in2_, const size_t size2_, const type type_)
{
	boolean out = FALSE;

	if (size1_ != size2_) return out;
	if (size1_ == WRONG_SIZE) return TRUE;

	boolean is_ok1 = array_is_ok(in1_, size1_, type_);
	boolean is_ok2 = array_is_ok(in2_, size2_, type_);

	if (is_ok1 == FALSE || is_ok2 == FALSE) return (is_ok1 == is_ok2 ? TRUE : FALSE);

	for (size_t i = 0; i < size1_; i++)
	{
		void* val1 = __assign_void(get_array_value(in1_, i, type_), type_);
		void* val2 = __assign_void(get_array_value(in2_, i, type_), type_);

		out = voids_are_equal(val1, val2, type_);

		free_void(val1, type_);
		free_void(val2, type_);

		if (out == FALSE) break;
	}

	return out;
}

void* __shrink_array(void* in_, const size_t new_size_, const type type_) { return (array_is_ok(in_, new_size_, type_) == TRUE ? __shrink_array_internal(in_, new_size_, type_, WRONG_POINTER, FALSE, WRONG_SIZE) : in_); }

void* get_array_value(void* in_, const size_t i_, const type type_)
{
	void* out;

	if (array_is_ok_internal(in_) == FALSE) out = get_wrong_void(type_);
	else if (type_array_is_2d_pointer(type_) == TRUE) out = get_2d_pointer_array_value_internal(in_, i_, type_);
	else out = get_array_value_default_internal(in_, i_, type_);

	return out;
}

type get_type_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_type(get_array_value(in_, i_, TYPE)) : WRONG_TYPE); }

type_error get_error_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_error(get_array_value(in_, i_, ERROR)) : WRONG_ERROR); }

type_warning get_warning_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_warning(get_array_value(in_, i_, WARNING)) : WRONG_WARNING); }

error_warning* get_error_warning_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_error_warning(get_array_value(in_, i_, ERROR_WARNING)) : WRONG_ERROR_WARNING); }

output* get_output_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_output(get_array_value(in_, i_, OUTPUT)) : WRONG_OUTPUT); }

boolean get_boolean_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_boolean(get_array_value(in_, i_, BOOLEAN)) : WRONG_BOOLEAN); }

char* get_string_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_string(get_array_value(in_, i_, STRING)) : WRONG_STRING); }

char get_char_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_char(get_array_value(in_, i_, CHAR)) : WRONG_CHAR); }

int get_int_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_int(get_array_value(in_, i_, INT)) : WRONG_INT); }

size_t get_size_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_size(get_array_value(in_, i_, SIZE)) : WRONG_SIZE); }

short get_short_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_short(get_array_value(in_, i_, SHORT)) : WRONG_SHORT); }

long get_long_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_long(get_array_value(in_, i_, LONG)) : WRONG_LONG); }

double get_double_array_value(void* in_, const size_t i_) { return (void_is_ok(in_) == TRUE ? void_to_double(get_array_value(in_, i_, DOUBLE)) : WRONG_DOUBLE); }

void* _update_array(void* array_, void* value_, const size_t i_, const type type_)
{
	if (array_is_ok_internal(array_) == FALSE) return array_;

	if (type_array_is_2d_pointer(type_) == TRUE) array_ = __update_2d_pointer_array_internal(array_, value_, i_, type_);
	else array_ = update_array_default_internal(array_, value_, i_, type_);

	return array_;
}

boolean update_array_is_heap(const type type_) { return type_array_is_2d_pointer(type_); }

void print_array(void* in_, const size_t size_, const type type_)
{
	if (array_is_ok(in_, size_, type_) == TRUE) _print_array_to_string_internal(in_, size_, type_, TRUE);
}

char* __array_to_string(void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? _print_array_to_string_internal(in_, size_, type_, FALSE) : __get_wrong_string_heap()); }

void* __assign_array_internal(void* out_, void* in_, const size_t size_, const type type_, size_t* sizes_items_, const boolean free_out_, const boolean free_in_)
{
	if (free_out_) free_array(out_, size_, type_);

	if (array_is_ok(in_, size_, type_) == FALSE)
	{
		if (free_in_) free_array(in_, size_, type_);

		out_ = __get_wrong_array_heap();
	}
	else if (type_array_is_2d_pointer(type_) == TRUE)
	{
		out_ = __initialise_update_2d_pointer_array_internal(__initialise_array_items(size_, type_, sizes_items_), in_, size_, type_, WRONG_SIZE, UPDATE);
	}
	else out_ = __assign(in_, size_, type_, TRUE);

	if (free_in_) free_array(in_, size_, type_);

	return out_;
}

void* __initialise_update_2d_pointer_array_internal(void* out_, void* in_, const size_t size_, const type type_, const size_t size_item_, const action action_)
{
	for (size_t i = 0; i < size_; i++)
	{
		if (action_ == INITIALISE) out_ = __initialise_2d_pointer_array_item_internal(out_, i, type_, size_item_);
		else
		{
			void* value = __assign_void(get_array_value(in_, i, type_), type_);

			out_ = __update_2d_pointer_array_item_internal(out_, value, i, type_);

			free_void(value, type_);
		}
	}

	return out_;
}

void* __initialise_2d_pointer_array_item_internal(void* out_, const size_t i_, const type type_, const size_t size_item_)
{
	if (type_ == ERROR_WARNING) ((error_warning**)out_)[i_] = __initialise_void(type_);
	else if (type_ == OUTPUT) ((output**)out_)[i_] = __initialise_void(type_);
	else if (type_ == STRING) ((char**)out_)[i_] = __initialise_string((size_item_ > WRONG_SIZE ? size_item_ : DEFAULT_ARRAYS_ITEM_SIZE));

	return out_;
}

void* __update_2d_pointer_array_item_internal(void* out_, void* value_, const size_t i_, const type type_)
{
	void* out = get_array_value(out_, i_, type_);

	if (type_ == ERROR_WARNING) ((error_warning**)out_)[i_] = __update_error_warning(out, value_);
	else if (type_ == OUTPUT) ((output**)out_)[i_] = __update_output(out, value_);
	else if (type_ == STRING) ((char**)out_)[i_] = __update_string(out, value_, TRUE);

	return out_;
}

void* __get_wrong_array_internal(void* out_, void* in_, const size_t size_, const type type_, const boolean free_out_, const boolean free_in_)
{
	if (free_out_) free_array(out_, size_, type_);
	if (free_in_) free_array(in_, size_, type_);

	return __get_wrong_array_heap();
}

void free_array_internal(void* in_h_, const size_t i_, const type type_) { if (in_h_ != WRONG_POINTER) free_void(get_array_value(in_h_, i_, type_), type_); }

boolean array_is_ok_internal(void* in_) { return pointer_is_ok(in_); }

void* __shrink_array_internal(void* in_, const size_t new_size_, const type type_, size_t* sizes_items_, const boolean free_in_, const size_t orig_size_)
{
	void* out = __initialise_array_items(new_size_, type_, sizes_items_);

	boolean is_2d = type_array_is_2d_pointer(type_);

	for (size_t i = 0; i < new_size_; i++)
	{
		void* value;

		if (is_2d == TRUE)
		{
			value = __assign_void(get_array_value(in_, i, type_), type_);

			out = __update_2d_pointer_array_internal(out, value, i, type_);
		}
		else
		{
			value = __assign_void(get_array_value(in_, i, type_), type_);

			out = update_array_default_internal(out, value, i, type_);
		}

		free_void(value, type_);
	}

	if (free_in_ == TRUE) free_array(in_, orig_size_, type_);

	return out;
}

void* get_array_value_default_internal(void* in_, const size_t i_, const type type_)
{
	void* out;

	if (type_ == TYPE) out = type_pointer_to_void(&(void_to_type_array(in_)[i_]));
	else if (type_ == ERROR) out = error_pointer_to_void(&(void_to_error_array(in_)[i_]));
	else if (type_ == WARNING) out = warning_pointer_to_void(&(void_to_warning_array(in_)[i_]));
	else if (type_ == BOOLEAN) out = boolean_pointer_to_void(&(void_to_boolean_array(in_)[i_]));
	else if (type_ == CHAR) out = char_pointer_to_void(&(void_to_char_array(in_)[i_]));
	else if (type_ == INT) out = int_pointer_to_void(&(void_to_int_array(in_)[i_]));
	else if (type_ == SIZE) out = size_pointer_to_void(&(void_to_size_array(in_)[i_]));
	else if (type_ == SHORT) out = short_pointer_to_void(&(void_to_short_array(in_)[i_]));
	else if (type_ == LONG) out = long_pointer_to_void(&(void_to_long_array(in_)[i_]));
	else if (type_ == DOUBLE) out = double_pointer_to_void(&(void_to_double_array(in_)[i_]));
	else out = get_wrong_void(type_);

	return out;
}

void* get_2d_pointer_array_value_internal(void* in_, const size_t i_, const type type_)
{
	void* out;

	if (type_ == ERROR_WARNING) out = error_warning_pointer_to_void(void_to_error_warning_array(in_)[i_]);
	else if (type_ == OUTPUT) out = output_pointer_to_void(void_to_output_array(in_)[i_]);
	else if (type_ == STRING) out = string_pointer_to_void(void_to_string_array(in_)[i_]);
	else out = get_wrong_void(type_);

	return out;
}

void* update_array_default_internal(void* out_, void* value_, const size_t i_, const type type_)
{
	void* value = __assign_void(value_, type_);

	if (type_ == TYPE) ((type*)out_)[i_] = void_to_type(value);
	else if (type_ == ERROR) ((type_error*)out_)[i_] = void_to_error(value);
	else if (type_ == WARNING) ((type_warning*)out_)[i_] = void_to_warning(value);
	else if (type_ == BOOLEAN) ((boolean*)out_)[i_] = void_to_boolean(value);
	else if (type_ == CHAR) ((char*)out_)[i_] = void_to_char(value);
	else if (type_ == INT) ((int*)out_)[i_] = void_to_int(value);
	else if (type_ == SIZE) ((size_t*)out_)[i_] = void_to_size(value);
	else if (type_ == SHORT) ((short*)out_)[i_] = void_to_short(value);
	else if (type_ == LONG) ((long*)out_)[i_] = void_to_long(value);
	else if (type_ == DOUBLE) ((double*)out_)[i_] = void_to_double(value);

	free_void(value, type_);

	return out_;
}

void* __update_2d_pointer_array_internal(void* array_, void* value_, const size_t i_, const type type_) { return __update_2d_pointer_array_item_internal(array_, value_, i_, type_); }

char* _print_array_to_string_internal(void* in_, const size_t size_, const type type_, const boolean is_print_)
{
	char* out;

	if (is_print_ == TRUE)
	{
		out = WRONG_STRING;

		print_array_start_end_internal(TRUE);
	}
	else out = __initialise_string(size_ * DEFAULT_ARRAYS_ITEM_SIZE);

	size_t max_i = size_ - 1;

	char* format = get_type_format(type_);

	for (size_t i = 0; i <= max_i; i++)
	{
		void* value = __assign_void(get_array_value(in_, i, type_), type_);

		if (is_print_ == TRUE) print_array_item_internal(i, max_i, value, format, type_);
		else out = __array_to_string_internal(out, value, i, type_, FALSE);

		free_void(value, type_);
	}

	if (is_print_ == TRUE) print_array_start_end_internal(FALSE);
	else out = __array_to_string_internal(out, WRONG_POINTER, WRONG_SIZE, type_, TRUE);

	return out;
}

void print_array_start_end_internal(const boolean is_start_)
{
	print_string_internal((is_start_ == TRUE ? DEFAULT_ENCLOSURE_EXTERNAL_START : DEFAULT_ENCLOSURE_EXTERNAL_END), FALSE);

	if (is_start_ == FALSE) print_new_line();
}

void print_array_item_internal(const size_t i_, const size_t max_i_, void* variable_, char* format_, const type type_)
{
	print_internal(variable_, format_, type_, FALSE);

	if (i_ < max_i_) print_string_internal(DEFAULT_SEPARATOR_ITEMS, FALSE);
}

char* __array_to_string_internal(char* out_, void* item_, const size_t i_, const type type_, const boolean is_end_)
{
	char* out;

	boolean free_out = FALSE;

	if (is_end_ == TRUE || i_ > 0)
	{
		out = __assign_string(out_);

		free_out = TRUE;
	}

	if (is_end_ == TRUE)
	{
		char* temp[] = { DEFAULT_ENCLOSURE_EXTERNAL_START, out, DEFAULT_ENCLOSURE_EXTERNAL_END };

		out_ = __assign_free_both_string(out_, __concatenate_strings(temp, 3));
	}
	else
	{
		char* item = _void_type_to_string(item_, type_);

		if (i_ == 0) out_ = __assign_free_out_string(out_, item);
		else
		{
			char* temp[] = { out, DEFAULT_SEPARATOR_ITEMS, item };

			out_ = __assign_free_both_string(out_, __concatenate_strings(temp, 3));
		}

		if (void_type_to_string_is_heap(type_)) free_string(item);
	}

	if (free_out == TRUE) free_string(out);

	return out_;
}
