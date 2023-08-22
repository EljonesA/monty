#include "monty.h"

/**
 * push - adds a node onto a stack
 * @top: pointer to top of the stack
 * @data: value for the new node
 *
 * Return: void.
 */
void push(stack_t **top, unsigned int data)
{
	/* Create and initialize new node to push to the stack */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL) /* check memory allocation */
		exit(EXIT_FAILURE);

	new_node->prev = NULL;
	new_node->n = data;
	new_node->next = NULL;

	/* Add [push] the new node onto the stack */
	if (*top == NULL) /* handling empty node */
	{
		new_node->prev = NULL;
		*top = new_node;
	}
	else /* handling non-empty node  */
	{
		(*top)->next = new_node;
		new_node->prev = *top;
		*top = new_node;
	}
}

/**
 * pall - function to print all elements of a stack
 * @top: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: void.
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current_node = *top;
	(void)line_number;

	/* handle empty stack */
	if (*top == NULL)
		exit(EXIT_FAILURE);

	/* traverse the stack printing value of the curent node each time */
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->prev;
	}
}
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
    	if (*top == NULL) 
	{
    	    fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        	exit(EXIT_FAILURE);
    	}

    	temp = *top;
    	*top = (*top)->next;

    	free(temp);
	printf("pop succesful");
}
void free(stack_t *top)
{

	stack_t *temp = top;

	while (top)
	{
		temp = to->next;
		free(top);
		top = temp;
	}
}
