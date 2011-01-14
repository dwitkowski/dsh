#include <stdlib.h>

/* Wraps malloc in a function that checks return value */
void *alloc(size_t bytes)
{
	void *ret_addr = (void *) malloc(bytes);
	if ( ret_addr == NULL )
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		return ret_addr;
	}
}
