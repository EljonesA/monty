#include "monty.h"


int execute(char *data, stack_t **top, unsigned int line_number, FILE *file)
{
	int found;
	char *op, *arg;
	size_t i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	found = 0;
	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		op = strtok(data, " \t\n$");
		if (op == NULL || op[0] == '\n' || op[0] == '#')
		{
			continue; /* ignore empty\blank lines, comments */
		}
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL && strcmp(op, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				free(data);
				exit(EXIT_FAILURE);
			}
			if (arg == NULL && strcmp(op, "pop") == 0)
			{
				fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
				exit(EXIT_FAILURE);
			}
			variables.arg = arg;
			variables.data = atoi(arg);
			instructions[i].f(top, line_number);
			found = 1;
			break;
		}
	}
	if (!found  || instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
	return (1);
}
