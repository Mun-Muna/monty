#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * helper - function to help main
 * @_file: file to be read
 * @_choice: type instruction_t
 * @_stack: type stack_t
 */
void helper(FILE *_file, instruction_t _choice[], stack_t **_stack)
{
	char line[4096];
	char *token_1;
	unsigned int l = 1, i;

	while (fgets(line, sizeof(line), _file) != NULL)
	{
		token_1 = strtok(line, " ");
		if (token_1 != NULL)
		{
			for (i = 0; _choice[i].opcode != NULL; i++)
			{
				if (strcmp(token_1, _choice[i].opcode) == 0)
				{
					_choice[i].f(_stack, l);
					break;
				}
			}
			if (_choice[i].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", l, token_1);
				exit(EXIT_FAILURE);
			}
		}
		l++;
	}
}
