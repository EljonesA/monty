#include "monty.h"

void free_stack(stack_t *top)
{
    stack_t *current = top;
    stack_t *next;

    while (current != NULL)
    {
        next = current->prev; 
        free(current);       
        current = next;       
    }
}