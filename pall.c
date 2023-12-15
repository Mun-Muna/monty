#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * pall - prints all the values on the stack
 * @stack: type stack_t
 * @line_number: type unsigned int
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
