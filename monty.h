#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

extern char *flag;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: Opcode and its function for stack, queue, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct externVariable_s
{
	char *arg;
	FILE *file;
	int data;
	int flag;
}  externVariable_t;
extern externVariable_t variables;
int execute(char* data, stack_t **top, unsigned int line_number, FILE *file);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void push(stack_t **top, unsigned int data);
void pall(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void div_stack(stack_t **top, unsigned int line_number);
void mod(stack_t **top, unsigned int line_number);
void mul(stack_t **top, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
void queue(stack_t **h, unsigned int l)
void stack(stack_t **h, unsigned int l)
void free_stack(stack_t *top);

void print_stack(stack_t *top);


#endif /* MONTY_H */
