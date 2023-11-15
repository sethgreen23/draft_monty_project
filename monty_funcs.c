#include "monty.h"

/**
 * read_file - read the file lines
 * @filename: filename
 * @stack: stack
 *
 * Return: nothing
 */
void read_file(char *filename, stack_t **stack)
{
	size_t length = 0;
	ssize_t line_read = 0;

	/*Open the file*/
	global_vars->file = fopen(filename, "r");
	if (global_vars->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*read the lines*/
	global_vars->line = NULL;
	while ((line_read = getline(&global_vars->line, &length, global_vars->file)) != -1)
	{
		global_vars->line = NULL;
	}
}


