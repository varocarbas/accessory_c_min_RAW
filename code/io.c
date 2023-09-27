#include "headers/io.h"

void print(void* value_, const type type_)
{
	char* format = get_type_format(type_);

	if (string_is_ok(format)) print_internal(value_, format, type_, TRUE);
}

void print_new_line() { print_internal(string_pointer_to_void(get_new_line()), get_type_format(STRING), STRING, FALSE); }

char* get_new_line() { return "\n"; }

char get_new_line_char() { return '\n'; }

char* get_dir_separator() { return (OS == WINDOWS ? "\\" : "/"); }

char get_dir_separator_char() { return (OS == WINDOWS ? '\\' : '/'); }

char* __normalise_dir(char* in_) { return __normalise_dir_internal(in_, FALSE); }

char* __normalise_free_dir(char* in_) { return __normalise_dir_internal(in_, TRUE); }

char* __get_file_path(char** items_, const size_t size_) { return (array_is_ok(items_, size_, STRING) ? __get_path_internal(items_, size_, FALSE, DEFAULT_IO_PATH_IS_ABSOLUTE) : __get_wrong_string()); }

char* __get_dir_path(char** items_, const size_t size_) { return (array_is_ok(items_, size_, STRING) ? __get_path_internal(items_, size_, TRUE, DEFAULT_IO_PATH_IS_ABSOLUTE) : __get_wrong_string()); }

boolean file_exists(char* path_)
{
	boolean out = FALSE;

	FILE* file = open_file_internal(path_, READ, FALSE);

	if (pointer_is_ok(file))
	{
		out = TRUE;

		fclose(file);
	}

	return out;
}

boolean delete_file(char* path_) { return (remove(path_) == 0); }

output* __read_file_lines(char* path_)
{
	FILE* file = open_file(path_, READ);
	if (!pointer_is_ok(file)) return __get_wrong_output_error(STRING, ERROR_WRONG_FILE, string_pointer_to_void("__get_file_lines"));

	type type_ = STRING;

	size_t size = DEFAULT_IO_FILE_TOT_LINES;
	char** lines = __initialise_string_array(size);

	char new_line = get_new_line_char();

	size_t i = 0;
	size_t new_size = 0;

	while (!feof(file))
	{
		size_t length = DEFAULT_IO_FILE_LINE_SIZE;

		char* line = __initialise_string(length);

		size_t i2 = 0;
		size_t new_length = 0;

		while (TRUE)
		{
			char temp = fgetc(file);
			if (temp == new_line || feof(file)) break;

			new_length = i2 + 1;

			if (new_length > length)
			{
				line = __embiggen_free_string(line, new_length);

				length = new_length;
			}

			line[i2] = temp;

			i2 = new_length;
		}

		if (new_length == 0)
		{
			free_string(line);

			break;
		}

		line = add_string_termination_internal(line, new_length);

		if (new_length < length) line = __shrink_free_string(line, new_length);

		new_size = i + 1;

		if (new_size > size)
		{
			lines = __embiggen_free_array(lines, new_size, type_, size);

			size = new_size;
		}

		lines =__update_string_array(lines, line, i);

		free_string(line);

		i = new_size;
	}

	new_size = i;

	close_file(file);

	if (new_size == 0) lines = __assign_free_both_array(lines, __get_wrong_array(), new_size, type_);
	else if (new_size < size) lines = __shrink_free_array(lines, new_size, type_, size);

	return __get_new_output_array(lines, new_size, type_, TRUE);
}

boolean write_file_lines(char* path_, char** lines_, const size_t size_)
{
	boolean out = FALSE;
	if (!string_is_ok_internal(path_, FALSE) || !array_is_ok(lines_, size_, STRING)) return out;

	FILE* file = open_file_internal(path_, WRITE, FALSE);
	if (!pointer_is_ok(file)) return out;

	for (size_t i = 0; i < size_; i++)
	{
		if (!write_file_line_internal(file, lines_[i]))
		{
			close_file(file);

			return out;
		}
	}

	out = TRUE;

	close_file(file);

	return out;
}

boolean write_file_line(char* path_, char* line_)
{
	boolean out = FALSE;
	if (!string_is_ok_internal(path_, FALSE) || !string_is_ok_internal(line_, FALSE)) return out;

	FILE* file = open_file_internal(path_, WRITE, FALSE);

	if (pointer_is_ok(file))
	{
		out = write_file_line_internal(file, line_);

		close_file(file);
	}

	return out;
}

FILE* open_file(char* path_, action action_) { return open_file_internal(path_, action_, TRUE); }

void close_file(FILE* file_) { fclose(file_); }

void print_internal(void* value_, char* format_, const type type_, const boolean add_new_line_)
{
	if (type_is_custom(type_))
	{
		char* temp = _custom_void_type_to_string(value_, type_);

		printf(format_, temp);

		if (custom_void_type_to_string_is_heap(type_)) free_string(temp);
	}
	else if (type_ == STRING) printf(format_, void_to_string(value_));
	else if (type_ == CHAR) printf(format_, void_to_char(value_));
	else if (type_ == INT) printf(format_, void_to_int(value_));
	else if (type_ == SIZE) printf(format_, void_to_size(value_));
	else if (type_ == SHORT) printf(format_, void_to_short(value_));
	else if (type_ == LONG) printf(format_, void_to_long(value_));
	else if (type_ == DOUBLE) printf(format_, void_to_double(value_));
	else return;

	if (add_new_line_) print_new_line();
}

char* __normalise_dir_internal(char* in_, const boolean free_in_)
{
	char* out;

	size_t max_i = get_string_length_internal(in_, FALSE) - 1;

	if (max_i < 1) out = __get_wrong_string();
	else if (in_[max_i] != get_dir_separator_char()) out = __add_to_string(in_, get_dir_separator());
	else out = __assign_string(in_);

	if (free_in_) free_string(in_);

	return out;
}

char* __get_path_internal(char** items_, const size_t size_, const boolean is_dir_, const boolean is_absolute_)
{
	size_t length = (DEFAULT_IO_NAME_SIZE + 1) * size_;

	char* out;

	size_t length2 = 0;
	size_t max_i = size_ - 1;

	char* separator = get_dir_separator();

	for (size_t i = 0; i <= max_i; i++)
	{
		char* item = __assign_string(items_[i]);
		if (is_dir_ || i < max_i) item = __add_to_free_string(item, separator);

		out = (i == 0 ? __assign_string(item) : __add_to_free_string(out, item));

		free_string(item);
	}

	if (length2 < length) out = __shrink_free_string(out, length2);

	if (is_absolute_)
	{
		if (os_is_unix()) out = __assign_free_both_string(out, __add_to_string(separator, out));
	}

	if (is_dir_) out = __normalise_free_dir(out);

	return out;
}

boolean write_file_line_internal(FILE* file_, char* line_)
{
	char* line = __add_to_string(line_, get_new_line());

	boolean out = (fputs(line, file_) != EOF);

	free_string(line);

	return out;
}

FILE* open_file_internal(char* path_, action action_, boolean check_exists_)
{
	FILE* out = WRONG_POINTER;
	if (!string_is_ok_internal(path_, FALSE) || (check_exists_ && action_ != READ && !file_exists(path_))) return out;

	char* mode;

	if (action_ == READ) mode = "r";
	else if (action_ == WRITE) mode = "w";
	else mode = WRONG_STRING;

	if (string_is_ok_internal(mode, FALSE)) out = fopen(path_, mode);

	return out;
}
