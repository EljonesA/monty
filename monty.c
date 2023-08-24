#include "monty.h"
 externVariable_t variables = {NULL, NULL, 0, 0};
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
	stack_t *top = NULL; /* the stack */
	
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
	variables.file = file;
	while (getline(&line, &len, file) != -1)
	{
		line_number++; /* make line_number 1 to indicate first line */
		execute(line, &top, line_number, file);
	}
	fclose(file);
	free(line);
	free_stack(top);
	return (0);
}
