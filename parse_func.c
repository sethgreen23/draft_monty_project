#include "monty.h"

/**
 * push - push element to the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *layer = NULL, *temp = NULL;

	(void)line_number;
	layer = malloc(sizeof(stack_t));
	if (layer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	layer->n = get_arg();
	if (get_mode() == 1)
	{
		/*printf("Stack Mode\n");*/
		layer->next = NULL;
		layer->prev = *stack;
		if (!is_empty(*stack))
		{
			(*stack)->next = layer;
		}
		*stack = layer;
	}
	else if (get_mode() == 2)
	{
		/*printf("Queue Mode\n");*/
		if (is_empty(*stack))
		{
			layer->next = NULL;
			layer->prev = NULL;
			*stack = layer;
		}
		else
		{
			temp = *stack;
			while (temp->prev != NULL)
				temp = temp->prev;
			layer->next = temp;
			layer->prev = NULL;
			temp->prev = layer;
		}
	}
}

/**
 * pall - print the elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	/*printf("Print function\n");*/
	(void)line_number;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * pint - print the top most stack node
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - delete the top most layer of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		(*stack)->next = NULL;
		free(*stack), *stack = NULL;
	}
	else
	{
		temp = *stack;
		/*shouldn't stack -> next == NULL?*/
		*stack = (*stack)->prev;
		temp->prev = NULL;
		temp->next = NULL;
		free(temp), temp = NULL;
	}
}

/**
 * swap - swap the top two elements of the slack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
