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
    stack_t *h;

    if (*top == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free_stack(*top);
        exit(EXIT_FAILURE);
    }
    h = *top;
    *top = h->next;
    free(h);
}
