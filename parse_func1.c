#include "monty.h"

/**
 * add - print the elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->prev->n;
	(*stack)->prev->n = temp;
	pop(stack, line_number);
}
