#include "monty.h"

void print_stack(stack_t *top)
{
    printf("Stack contents:\n");
    while (top != NULL)
    {
        printf("%d\n", top->n);
        top = top->next;
    }
}