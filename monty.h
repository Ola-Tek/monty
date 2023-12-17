#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void file_opened(char *file_desc);
int parseline_file(char *buffer, int line_number, int format);
void readin_file(FILE *fd);
int length_chars(FILE *);
void seek_func(char *, char *, int, int);
void free_nodes(void);
stack_t *build_node(int n);
void add_stack(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void add_in_queue(stack_t **, unsigned int);
void call_func(op_func, char *, char *, int, int);
void top_print(stack_t **, unsigned int);
void pop_t(stack_t **, unsigned int);
void nop_t(stack_t **, unsigned int);
void swap_n(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void divide_nodes(stack_t **, unsigned int);
void multiply_nodes(stack_t **, unsigned int);
void module_nodes(stack_t **, unsigned int);
void error(int err_cd, ...);
void more_errors(int err_cd, ...);
void str_error(int err_cd, ...);
void rotr(stack_t **, unsigned int);
void pri_chars(stack_t **, unsigned int);
void pri_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

#endif /*_MONTY_H*/
