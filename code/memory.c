#include "headers/memory.h"

void* __malloc(const size_t size_, const type type_)
{
	size_t size = get_heap_stack_size(size_, type_, TRUE);

	return (size > WRONG_SIZE ? malloc(size) : WRONG_POINTER);
}

size_t get_heap_stack_size(const size_t size_, const type type_, const boolean is_heap_)
{
    if (type_is_ok(type_) == FALSE || (size_ == WRONG_SIZE && type_ != STRING)) return WRONG_SIZE;

    size_t output = size_;
    if (type_ == STRING) output++;

    if (is_heap_ == TRUE) output *= get_type_size(type_);

    return output;
}
