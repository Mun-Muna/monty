#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: string
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t **stack = malloc(sizeof(stack_t *));
	instruction_t choice[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};

	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	helper(file, choice, &stack);
	fclose(file);
	return (0);
}
