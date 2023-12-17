#include "monty.h"
stack_t *head = NULL;

/**
 * add_stack - adds to stack
 * @new_n: new node
 * @line_no: line number of the stack
 */
void add_stack(stack_t **new_n, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	temp = head;
	head = *new_n;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - adds a node to the stack
 * @stack: pointer to a pointer pointing
 * @line_no: line number of the opcode
 */
void print_stack(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	(void) line_no;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pri_chars - print characters
 * @stack: stack pointer
 * @line_no: line number
 */
void pri_chars(stack_t **stack, unsigned int line_no)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		str_error(11, line_no);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		str_error(10, line_no);
	printf("%c\n", ascii);
}

/**
 * pri_str - print string
 * @stack: pointer to the stack
 * @line_no: line number
 */
void pri_str(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * add_in_queue - add to the queue
 * @new_n: new node
 * @line_no: line number
 */
void add_in_queue(stack_t **new_n, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
}
