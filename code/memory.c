#include "headers/memory.h"

void* __initialise(const size_t tot_items_, const type type_, const boolean is_array_) { return ((type_ != WRONG_TYPE && (tot_items_ > WRONG_SIZE || type_ == STRING)) ? __initialise_internal(get_memory_size(tot_items_, type_, is_array_, TRUE)) : __get_wrong(type_, is_array_)); }

void* __initialise_custom(void* in_, const type type_)
{
	void* out;

	if (void_type_is_ok(in_, type_) == FALSE) out = __get_wrong_void(type_);
	else if (type_ == ERROR_WARNING) out = __initialise_error_warning_internal(*((error_warning*)in_));
	else if (type_ == OUTPUT) out = __initialise_output_internal(*((output*)in_));
	else out = __get_wrong_void(type_);

	return out;
}

void* __assign(void* in_, const size_t tot_items_, const type type_, const boolean is_array_) { return __assign_free_internal(in_, tot_items_, type_, is_array_, FALSE); }

void* __assign_free_in(void* in_h_, const size_t tot_items_, const type type_, const boolean is_array_) { return __assign_free_internal(in_h_, tot_items_, type_, is_array_, TRUE); }

void* __assign_free_out(void* out_h_, void* in_, const size_t tot_items_, const type type_, const boolean is_array_)
{
	free_(out_h_, (is_array_ == TRUE ? tot_items_ : WRONG_SIZE), type_);

	out_h_ = __assign_free_internal(in_, tot_items_, type_, is_array_, FALSE);

	return out_h_;
}

void* __assign_free_both(void* out_h_, void* in_h_, const size_t tot_items_, const type type_, const boolean is_array_)
{
	free_(out_h_, (is_array_ == TRUE ? tot_items_ : WRONG_SIZE), type_);

	out_h_ = __assign_free_internal(in_h_, tot_items_, type_, is_array_, TRUE);

	return out_h_;
}

void free_(void* in_h_, const size_t size_array_, const type type_)
{
	if (is_array(size_array_) == TRUE) free_array(in_h_, size_array_, type_);
	else free_internal(in_h_, type_, FALSE);
}

void free_2d_pointer(void* in_h_, const size_t size_, const type type_)
{
	if (array_is_ok(in_h_, size_, type_) == TRUE)
	{
		for (size_t i = 0; i < size_; i++) { free_2d_pointer_internal(in_h_, i, type_); }
	}

	free_internal(in_h_, type_, TRUE);
}

void* _get_wrong(const type type_, const boolean is_array_, const boolean is_heap_) { return (is_heap_ ? __get_wrong(type_, is_array_) : get_wrong(type_, is_array_)); }

void* get_wrong(const type type_, const boolean is_array_) { return get_wrong_internal(type_, is_array_); }

void* __get_wrong(const type type_, const boolean is_array_)
{
	void* out;

	size_t size = 0;

	if (type_ == WRONG_TYPE) out = __initialise_internal(get_type_size(WRONG_SIZE, FALSE));
	else if (type_ == ERROR_WARNING) out = __get_wrong_error_warning();
	else if (type_ == OUTPUT) out = __get_wrong_output();
	else if (type_ == STRING)
	{
		out = __initialise(size, type_, is_array_);

		if (pointer_is_ok(out) == TRUE) out = add_string_termination_internal(out, size);
	}
	else
	{
		size = 1;

		out = _assign_internal(__initialise(size, type_, is_array_), get_wrong_internal(type_, is_array_), size, type_, is_array_);
	}

	return out;
}

void* __get_wrong_free(void* in_out_h_, const size_t array_size_, const type type_)
{
	free_(in_out_h_, array_size_, type_);

	return __get_wrong(type_, FALSE);
}

void* __get_wrong_free_both(void* out_h_, void* in_h_, const size_t array_size_, const type type_)
{
	free_(out_h_, array_size_, type_);
	free_(in_h_, array_size_, type_);

	return __get_wrong(type_, FALSE);
}

boolean pointer_is_ok(void* in_) { return ((in_ != WRONG_POINTER) ? TRUE : FALSE); }

size_t get_memory_size(const size_t tot_items_, const type type_, const boolean is_2d_pointer_, const boolean is_heap_)
{
    if (type_ == WRONG_TYPE || (tot_items_ == WRONG_SIZE && type_ != STRING)) return (is_heap_ ? get_type_size(WRONG_SIZE, is_2d_pointer_) : WRONG_SIZE);

    size_t out = tot_items_;
    if (type_ == STRING && is_2d_pointer_ == FALSE) out++;

    if (is_heap_) out *= get_type_size(type_, is_2d_pointer_);

    return out;
}

void free_internal(void* in_h_, const type type_, const boolean only_native_)
{
	if (only_native_ == TRUE) free(in_h_);
	else if (type_ == ERROR_WARNING) free_error_warning(in_h_);
	else if (type_ == OUTPUT) free_output(in_h_);
	else free(in_h_);
}

void free_2d_pointer_internal(void* in_h_, const size_t i_, const type type_) { if (in_h_ != WRONG_POINTER) free_void(get_array_item(in_h_, i_, type_), type_); }

void* __assign_free_internal(void* in_, const size_t tot_items_, const type type_, const boolean is_array_, const boolean free_in_)
{
	size_t size = get_memory_size(tot_items_, type_, is_array_, TRUE);

	void* out = __initialise_internal(size);

	out = ((pointer_is_ok(out) == TRUE) ? _assign_internal(out, in_, size, type_, is_array_) : __get_wrong(type_, is_array_));

	if (pointer_is_ok(out) == TRUE)
	{
		if (type_is_custom(type_) == TRUE) out = __assign_free_custom_internal(out, in_, (is_array_ ? tot_items_ : WRONG_SIZE), type_);
	}
	else out = __get_wrong(type_, is_array_);

	if (free_in_) free_(in_, (is_array_ ? tot_items_ : WRONG_SIZE), type_);

	return out;
}

void* __assign_free_custom_internal(void* out_, void* in_, const size_t tot_items_, const type type_)
{
	if (tot_items_ == WRONG_SIZE) return __assign_free_custom_item_internal(out_, in_, type_);
	else if (array_is_ok(out_, tot_items_, type_) == FALSE || array_is_ok(in_, tot_items_, type_) == FALSE) return out_;

	for (size_t i = 0; i < tot_items_; i++)
	{
		void* out = __get_array_value(out_, i, type_);
		void* in = __get_array_value(in_, i, type_);

		if (type_ == ERROR_WARNING) ((error_warning**)out_)[i] = __assign_free_custom_item_internal(out, in, type_);
		else if (type_ == OUTPUT) ((output**)out_)[i] = __assign_free_custom_item_internal(out, in, type_);

		free_void(out, type_);
		free_void(in, type_);
	}

	return out_;
}

void* __assign_free_custom_item_internal(void* out_, void* in_, const type type_)
{
	if (type_ == ERROR_WARNING) out_ = __assign_error_warning_internal(out_, in_);
	else if (type_ == OUTPUT) out_ = __assign_output_internal(out_, in_);

	return out_;
}

void* _assign_internal(void* out_, void* in_, const size_t size_, const type type_, const boolean is_array_) { return (type_ == STRING ? strcpy(out_, in_) : memcpy(out_, in_, size_)); }

void* __initialise_internal(const size_t size_) { return malloc(size_); }

void* get_wrong_internal(const type type_, const boolean is_array_)
{
	void* out;

	if (is_array_ == TRUE || type_ == WRONG_TYPE) out = WRONG_POINTER;
	else if (type_ == TYPE) out = &WRONG_TYPE;
	else if (type_ == ERROR) out = &WRONG_ERROR;
	else if (type_ == WARNING) out = &WRONG_WARNING;
	else if (type_ == ERROR_WARNING) out = WRONG_ERROR_WARNING;
	else if (type_ == OUTPUT) out = WRONG_OUTPUT;
	else if (type_ == BOOLEAN) out = &WRONG_BOOLEAN;
	else if (type_ == STRING) out = WRONG_STRING;
	else if (type_ == CHAR) out = &WRONG_CHAR;
	else if (type_ == INT) out = &WRONG_INT;
	else if (type_ == SIZE) out = &WRONG_SIZE;
	else if (type_ == SHORT) out = &WRONG_SHORT;
	else if (type_ == LONG) out = &WRONG_LONG;
	else if (type_ == DOUBLE) out = &WRONG_DOUBLE;
	else out = WRONG_POINTER;

	return out;
}
