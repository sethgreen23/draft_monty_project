#include "monty.h"
static int mode = 1;
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
	/* reading the file*/
	read_file(argv[1], &stack);
	if (!is_empty(stack))
	{
		free_stack(&stack);
	}
	return (0);
}
/**
 * get_mode - get the current mode
 *
 * Return: mode
 */
int get_mode(void)
{
	return (mode);
}
/**
 * set_mode - get the current mode
 * @val: val
 *
 * Return: set mode to 1 or 2
 */
void set_mode(int val)
{
	mode = val;
}
