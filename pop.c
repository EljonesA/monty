#include "monty.h"

/**
 * pop - deletes the last node in the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
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

    if (*top != NULL)
    {
        (*top)->prev = NULL;
       
    }

    free(temp);
    
    
}
