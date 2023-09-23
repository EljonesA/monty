#include "monty.h"


void queue(stack_t **h, unsigned int l)
{
    (void)h;
    (void)l;
    is_queue = 1;  
    printf("queue mode\n");
}

void stack(stack_t **h, unsigned int l)
{
    (void)h;
    (void)l;
    is_queue = 0;  
    printf("queue mode\n");

}
