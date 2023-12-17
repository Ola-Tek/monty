#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argumnt vector
 * Return: 0, on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_opened(argv[1]);
	free_nodes();
	return (0);
}

/**
 * top_print - prints the top node of tge stack
 * @stack: pointer to the stack
 * @line_no: line number
 */
void top_print(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, line_no);
	printf("%d\n", (*stack)->n);
}
