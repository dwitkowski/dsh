#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/util.h"
#include "headers/input.h"

char *SHELL_PROMPT = "[dsh]$ ";

int main(int argc, char *argv[])
{
	char *line;
	
	while( 1 )
	{
		printf(SHELL_PROMPT);
		read_stdin(&line);
		printf("Read: %s\n", line);
	}
	return 0;
}


