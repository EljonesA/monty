#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
void add(stack_t **top, unsigned int line_number)
{
	int sum;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*top)->n + (*top)->next->n;
	pop(top, line_number);
	(*top)->n = sum;
}
