#include "monty.h"

/**
 * div - div the top two elements of the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
void div_stack(stack_t **top, unsigned int line_number)
{
    stack_t *current;
    int highest, second_highest, result;

    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    highest = (*top)->n;
    second_highest = (*top)->next->n;

    if(highest == 0)
    {
        fprintf(stderr, "L%d: division by zero", line_number);
        exit(EXIT_FAILURE);

    }
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

    result = highest / second_highest;

    (*top)->n = result;
}


/**
 * mul - div the top two elements of the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
void mul(stack_t **top, unsigned int line_number)
{
	int mul;

    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    mul = (*top)->n - (*top)->next->n;

  
    (*top)->n = mul; 
}
/**
 * mod - div the top two elements of the stack
 * @top: pointer to top of the stack
 * @line_number: line number of the instruction
 *
 * Return: void.
 */
void mod(stack_t **top, unsigned int line_number)
{
	int mul;

    if (*top == NULL || (*top)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    mul = (*top)->n - (*top)->next->n;

    
    (*top)->n = mul; 
}
