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
	size_t len = 0;
	ssize_t lread = 0;
	char *opcode;
	int line_num = 0;

	/*Open the file*/
	global_vars->file = fopen(filename, "r");
	if (global_vars->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*read the lines*/

	global_vars->line = NULL;
	while ((lread = getline(&global_vars->line, &len, global_vars->file)) != -1)
	{
		opcode = parse_line();
		if (opcode == NULL)
		{
			line_num++;
			continue;
		}

		line_num++;
	}
}

/**
 * parse_line - parse the line
 *
 * Return: opcode or NULL
 */
char *parse_line()
{
	char *opcode = NULL;
	char *argument = NULL;

	/*start by tokenize the string to get the opcode*/
	opcode = strtok(global_vars->line, " \n");
	if (opcode == NULL)
		return (NULL);
	if (strcmp(opcode, "push") == 0)
	{
		argument = strtok(NULL, " \n");
		if (argument != NULL && is_numerical(argument))
		{
			global_vars->arg = atoi(argument);
		}
		else
		{
			fprintf(stderr, "USAGE: push arg\n");
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}
/**
 * is_numerical - is a number
 * @str: string to check
 *
 * Return: 1 if number 0 if not
 */
int is_numerical(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
/**
 * get_opcode_func - get associete function to the opcode
 * @opcode: string
 *
 * Return: appropriete function or NULL
 */
inst_fun get_opcode_func(char *opcode)
{
	int i = 0;

	instruction_t instructions[3] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	while (instructions[i].f != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);
}
