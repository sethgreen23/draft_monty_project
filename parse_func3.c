#include "monty.h"
static int mode = 1;
/**
 * stack - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
	if (mode == 1)
		return;
	mode = 1;
}

/**
 * queue - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	if (mode == 2)
		return;
	mode = 2;
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
