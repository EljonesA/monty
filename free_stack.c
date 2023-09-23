#include "monty.h"

void free_stack(stack_t *top)
{
    stack_t *current = top;
    stack_t *cur;

    while (current != NULL)
    {
        cur = current->prev; 
        free(current);       
        current = cur;       
    }
}