#include "headers/arrays.h"

void* assign_array(void* out_, void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? assign(out_, in_, type_, size_) : get_wrong_array_stack(type_)); }

void* __initialise_array(const size_t size_, const type type_) { return __initialise(size_, type_, TRUE); }

void* __assign_array(void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign(in_, size_, type_, TRUE) : __assign_wrong_array(size_, type_)); }

void* __assign_free_in_array(void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE? __assign_free_in(in_h_, size_, type_, TRUE) : __assign_free_wrong_array(in_h_, size_, type_)); }

void* __assign_free_out_array(void* out_h_, void* in_, const size_t size_, const type type_) { return (array_is_ok(in_, size_, type_) == TRUE ? __assign_free_out(out_h_, in_, size_, type_, TRUE) : __assign_free_wrong_array(out_h_, size_, type_)); }

void* __assign_free_both_array(void* out_h_, void* in_h_, const size_t size_, const type type_) { return (array_is_ok(in_h_, size_, type_) == TRUE ? __assign_free_both(out_h_, in_h_, size_, type_, TRUE) : __assign_free_both_wrong_array(out_h_, in_h_, size_, type_)); }

void* __assign_wrong_array(const size_t size_, const type type_) { return __assign_wrong(size_, type_, TRUE); }

void* __assign_free_wrong_array(void* in_out_h_, const size_t size_, const type type_) { return __assign_free_wrong(in_out_h_, size_, type_, TRUE); }

void* __assign_free_both_wrong_array(void* out_h_, void* in_h_, const size_t size_, const type type_) { return __assign_free_both_wrong(out_h_, in_h_, size_, type_, TRUE); }

void free_2d_array(void* in_h_, const size_t size_, const type type_)
{
	if (array_is_ok(in_h_, size_, type_) == TRUE)
	{
		for (size_t i = 0; i < size_; i++) { free_array_internal(in_h_, i, type_); }
	}

	free(in_h_);
}

void* _get_wrong_array(const type type_, const boolean is_heap_) { return _get_wrong(type_, TRUE, is_heap_); }

void* get_wrong_array_stack(const type type_) { return get_wrong_stack(type_, TRUE); }

void* __get_wrong_array_heap(const type type_) { return __get_wrong_heap(type_, TRUE); }

boolean array_is_ok(void* in_, const size_t size_, const type type_) { return (array_is_ok_internal(in_) == TRUE && size_ > WRONG_SIZE && type_ != WRONG_TYPE); }

size_t get_initial_array_size(const size_t size_, const type type_, const boolean is_heap_) { return get_memory_size(size_, type_, is_heap_); }

void print_array(void* in_, const size_t size_, const type type_)
{
	if (array_is_ok(in_, size_, type_) == FALSE) return;

	print_array_start_end_internal(TRUE);

	const size_t max_i = size_ - 1;

	for (size_t i = 0; i <= max_i; i++)
	{
		void* temp;

		if (type_ == ERROR_WARNING) temp = void_to_error_warning_array(in_)[i];
		else if (type_ == OUTPUT) temp = void_to_output_array(in_)[i];
		else if (type_ == STRING) temp = void_to_string_array(in_)[i];
		else temp = get_void_array_item(in_, i, type_);

		print_array_item_internal(i, max_i, temp, get_type_format(type_), type_);
	}

	print_array_start_end_internal(FALSE);
}

boolean array_is_ok_internal(void* in_) { return pointer_is_ok(in_); }

void free_array_internal(void* in_h_, const size_t i_, const type type_) { free_(get_void_array_item(in_h_, i_, type_), type_); }

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
