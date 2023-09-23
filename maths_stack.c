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
    (*top)->n = sum; 
}
/**
 * sub - subs the top highest element from the second highest elements of the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
void sub(stack_t **top, unsigned int line_number)
{
    stack_t *current;
    int highest, second_highest, result;

    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    highest = (*top)->n;
    second_highest = (*top)->next->n;
    
    current = (*top)->next->next;
    while (current != NULL)
    {
        if (current->n > highest)
        {
            second_highest = highest;
            highest = current->n;
        }
        else if (current->n > second_highest)
        {
            second_highest = current->n;
        }
        current = current->next;
    }

    result =  highest - second_highest;

    (*top)->n = result;
}
