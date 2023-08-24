#include "monty.h"

/**
 * main - runs the monty program
 * @argc: argument count
 * @argv: argument strings
 *
 * Return: 0 (Always success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int line_number = 0;
	char *opcode;
	stack_t *top = NULL; /* the stack */
	int i = 0;
	char *arg;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

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

	while (getline(&line, &len, file) != -1)
	{
		line_number++; /* make line_number 1 to indicate first line */
		opcode = strtok(line, " \t\n$");

		if (opcode == NULL || opcode[0] == '\n' || opcode[0] == '#')
		{
			continue; /* ignore empty\blank lines, comments */
		}

		/* tokenize arguments if needed */
		arg = strtok(NULL, " \t\n");
		if (strcmp(opcode, "push") == 0 && arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&top, line_number);
				break;
			}
			i++;
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instructions %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free(line);

	return (0);
}
