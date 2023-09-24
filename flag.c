#include "monty.h"

int is_queue = 0;  // Global variable to track whether it's a stack (0) or queue (1)

void queue(stack_t **h, unsigned int l)
{
    (void)h;
    (void)l;
    is_queue = 1;  // Set to queue mode
}

void stack(stack_t **h, unsigned int l)
{
    (void)h;
    (void)l;
    is_queue = 0;  // Set to stack mode
}