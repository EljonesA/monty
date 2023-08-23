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
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	size_t len = 0;
	int line_number = 0;
	char *opcode;
	stack_t *top = NULL; /* the stack */
	int found;
	char *arg;
	size_t i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

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

		found = 0;
		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				arg = strtok(NULL, " \t\n");
				if (arg == NULL && strcmp(opcode, "push") == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(&top, line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free(line);

	return (0);
}
