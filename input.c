#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "headers/util.h"

/* Reads a character stream from stdin until a linefeed is encountered and
 * returns the number of characters read. */
int read_stdin(char *line_buffer)
{
	char **ret_ptr = line_buffer; // Holds address of pointer outside of function.
	char *str_start_ptr, *str_cur_ptr, ch;
	int MAX_CHAR = 40, num_chars_read = 0;
	str_start_ptr = (char *) alloc(sizeof(char) * MAX_CHAR);
	str_cur_ptr = str_start_ptr;
	
	while ( (ch = getchar()) != EOF )
	{
		// If only one char left in current string buffer.
		if ( num_chars_read == MAX_CHAR - 1 )
		{
			// Get new memory space that can hold MAX_CHAR more space than before.
			char *str_tmp_ptr = (char *) alloc(num_chars_read + 1 + MAX_CHAR);
			memcpy(str_tmp_ptr, str_start_ptr, num_chars_read);
			free(str_start_ptr);
			str_start_ptr = str_tmp_ptr;
			str_cur_ptr = str_tmp_ptr + num_chars_read;
		}
		
		if ( ch == '\n' )
		{
			*str_cur_ptr = '\0';
			*ret_ptr = str_start_ptr;
			return num_chars_read;
		}
		else
		{
			*str_cur_ptr = ch;
			++str_cur_ptr;
			++num_chars_read;
		}
	}
	exit(EXIT_SUCCESS);
}
