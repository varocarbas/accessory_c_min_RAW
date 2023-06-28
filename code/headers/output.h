#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "all.h"

output get_new_output(void*, type);

output get_wrong_output(type, void*, boolean, void*);

char* output_to_string(const output*);

output* update_output_log(output*, void*, boolean, void*);

#endif
