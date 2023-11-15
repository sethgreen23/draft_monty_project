#include "monty.h"

vars_global *global_vars;

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments table
 *
 * Return: 0 on Success, 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	/* check if the arguments are different to 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_vars = malloc(sizeof(vars_global));
    if (global_vars == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	global_vars->file = NULL;
	global_vars->arg = 0;
	global_vars->line = NULL;
	/* reading the file*/
	read_file(argv[1], &stack);
	exit(EXIT_SUCCESS);
	return (0);
}
