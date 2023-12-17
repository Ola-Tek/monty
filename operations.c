#include "monty.h"
/**
 * divide_nodes - adds the top two elent of the stack
 * @stack: pointer to the stack
 * @line_no: line number
 */
void divide_nodes(stack_t **stack, unsigned int line_no)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "div");

	if ((*stack)->n == 0)
		more_errors(9, line_no);
	(*stack) = (*stack)->next;
	addition = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * multiply_nodes - mul nodes
 * @stack: pointer to the stack
 * @line_no: line number
 */
void multiply_nodes(stack_t **stack, unsigned int line_no)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "mul");

	(*stack) = (*stack)->next;
	addition = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * module_nodes - mod of a node
 * @stack: pointer to the stack
 * @line_no: line number
 */
void  module_nodes(stack_t **stack, unsigned int line_no)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "mod");

	if ((*stack)->n == 0)
		more_errors(9, line_no);
	(*stack) = (*stack)->next;
	addition = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * add_nodes - add nodes
 * @stack: pointer to the stack
 * @line_no: line number
 */
void add_nodes(stack_t **stack, unsigned int line_no)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "add");

	(*stack) = (*stack)->next;
	addition = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - subtract nodes
 * @stack: pointer to the stack
 * @line_no: line number)
 */
void sub_nodes(stack_t **stack, unsigned int line_no)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_no, "sub");

	(*stack) = (*stack)->next;
	addition = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
