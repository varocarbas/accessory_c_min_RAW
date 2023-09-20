#ifndef IO_H_
#define IO_H_

#include "all.h"

void print(void*, type);

void print_new_line();

char* get_new_line();

char get_new_line_char();

char* get_dir_separator();

char get_dir_separator_char();

char* __normalise_dir(char*);

char* __normalise_free_dir(char*);

char* __get_file_path(char**, size_t);

char* __get_dir_path(char**, size_t);

boolean file_exists(char*);

boolean delete_file(char*);

output* __read_file_lines(char*);

boolean write_file_lines(char*, char**, size_t);

boolean write_file_line(char*, char*);

FILE* open_file(char*, action);

void close_file(FILE*);

void print_internal(void*, char*, type, boolean);

char* __normalise_dir_internal(char*, boolean);

char* __get_path_internal(char**, size_t, boolean, boolean);

boolean write_file_line_internal(FILE*, char*);

FILE* open_file_internal(char*, action, boolean);

#endif
