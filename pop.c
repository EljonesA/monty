#include "monty.h"

/**
 * pop - deletes the last in the stack
 * @top: pointer to top of the stack
 * @data: value for the new node
 *
 * Return: void.
 */
void pop(stack_t **top, unsigned int line_number) {
    stack_t *temp;
    if (*top == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *top;
    *top = (*top)->next;

    free(temp);
}