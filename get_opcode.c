#include "monty.h"
/**
 * execute - finds the function matching the opcode
 * @top: pointer to the node
 * @data: command line
 * @file: file to open
 * @line_number: line number of the command line in the file
 */
int execute(char *data, stack_t **top, unsigned int line_number, FILE *file)
{
    size_t i;

    instruction_t instructions[] = {
        {"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"add", add}, {"swap", swap},
        {"nop", nop}, {"sub", sub}, {"mod", mod},
        {"mul", mul}, {"div", div_stack}, 
        {"queue", queue}, {"stack", stack}, {NULL, NULL}
    };

    char *op = strtok(data, " \t\n$");
    if (op == NULL || op[0] == '\n' || op[0] == '#')
    {
        return 1;
    }
    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(op, instructions[i].opcode) == 0)
        {
            char *arg = strtok(NULL, " \t\n");
            
            if (strcmp(op, "push") == 0)
            {
                if (arg == NULL)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    fclose(file);
                    free(data);
                    free_stack(*top);
                    exit(EXIT_FAILURE);
                }
                variables.data = atoi(arg);
                push(top, variables.data);  
                return (1);
			}         
            else
            {
                variables.arg = arg;
                instructions[i].f(top, line_number);
                return (1);
            }
            
			
        }
	}
	  
    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
    exit(EXIT_FAILURE);
}
