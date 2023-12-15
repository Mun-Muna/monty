#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * push - pushes an element to the stack
 * @stack: type stack_t
 * @line_number: type unsigned int
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (token_2 == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	if (atoi(token_2) == 0 && strcmp(token_2, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(token_2);
	temp->prev = NULL;
	temp->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = temp;
	*stack = temp;
}
