#include "monty.h"

/**
 * push - push element to the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void push(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *layer = malloc(sizeof(stack_t));
	if (layer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	layer->n = global_vars.arg;
	layer->next = NULL;
	layer->prev = *stack;
	if (!(is_empty(*stack)))
	{
		(*stack)->next = layer;
	}
	*stack = layer;
}

/**
 * pall - print the elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}