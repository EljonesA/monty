#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @top: pointer to the top of the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_number)
{
	/* check if stack empty */
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
 * swap - swaps top two elements of the stack
 * @top: pointer to top of stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void swap(stack_t **top, unsigned int line_number)
{
	int temp;

	/* ensure stack has atleast two elements */
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* swap the values */
	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}

/**
 * nop - does nothing
 * @top: pointer to top of stack
 * @line_number: line number in the file
 *
 * Return: void.
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
	
}
