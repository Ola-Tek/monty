#include "monty.h"

/**
 * nop_t - does nothing
 * @stack: pointer to stack
 * @line_no: line number
 */
void nop_t(stack_t **stack, unsigned int line_no)
{
	(void) stack;
	(void) line_no;
}

/**
 * swap_n - swap nodes
 * @stack: pointer to stack
 * @line_no: line number
 */
void swap_n(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev =  temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * build_node - crrate new node
 * @new: new node
 * Return: a pointer upon success
 */
stack_t *build_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - free nodes
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * pop_t - Adds a node to the stack
 * @stack: pointer to the stack
 * @line_no: line number
 */
void pop_t(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_errors(7, line_no);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
