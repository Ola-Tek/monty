#include "monty.h"
/**
 * error - prints appropraite error message determined by error code
 * @err_cd: error codes are the following:
 * (1) => user does not give any file or more than one
 * (2) => file providedis not a file that can be opened or read
 * (3) => file contains individual instruction
 * (4) => program unable to allocate memory
 * (5) => parameter passed to the instruction "push" is not an int
 */
void error(int err_cd, ...)
{
	va_list ag;
	char *op;
	int line_no;

	va_start(ag, err_cd);
	switch (err_cd)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			line_no = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - handle more errors
 * @err_cd: error codes
 * (6) => stack is empty for pint
 * (7) => stack is empty for pop
 * (8) => stack too short for operation
 * (9) => division pertaining to stack
 */
void more_errors(int err_cd, ...)
{
	va_list arg;
	char *op;
	int line_no;

	va_start(arg, err_cd);
	switch (err_cd)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
			break;
		case 8:
			line_no = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_no, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_error -handles errors
 * @err_cd: the error codes
 * (10) => number inside a node is outside ASCII boards
 * (11) => the stack is empty
 */
void str_error(int err_cd, ...)
{
	va_list arg;
	int line_no;

	va_start(arg, err_cd);
	line_no = va_arg(arg, int);
	switch (err_cd)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * rotl - an important function
 * @stack: pointer to the stack
 * @line_no: line number of the stack
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - an important fuc
 * @stack: pointer to the stack
 * @line_no: line number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
