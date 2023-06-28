#ifndef LOGS_H_
#define LOGS_H_

#include "all.h"

char* log_to_string(const log*);

log get_new_log(void*, boolean, void*);

char* get_log_message_internal(void*, boolean, void*);

#endif
