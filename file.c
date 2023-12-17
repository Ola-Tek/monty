#include "monty.h"

/**
 * file_opened - opens a file
 * @file_desc: file name
 * Return: no return value
 */
void file_opened(char *file_desc)
{
	FILE *fd = fopen(file_desc, "r");

	if (file_desc == NULL || fd == NULL)
		error(2, file_desc);

	readin_file(fd);
	fclose(fd);
}

/**
 * readin_file - reads the content of file
 * @fd: file descriptor
 * Return: no return value
 */
void readin_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		format = parseline_file(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parseline_file - seperate each lines into tokens using a dlimeter
 * @buffer: line from the file
 * @line_number: line number
 * @format: storage format, if 0, nodes entered as stack. if 1, as queue
 * Return: 0, if opcode is stack. 1 if its queue
 */
int parseline_file(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delimeter = "\n";

	if (buffer ==  NULL)
		error(4);

	opcode = strtok(buffer, delimeter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	seek_func(opcode, val, line_number, format);
	return (format);
}

/**
 * seek_func - find the approprite func for opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format: storage format,0 nodes entered as stack, 1 nodes entered as queue
 * @line_no: line number
 * Return: void
 */
void seek_func(char *opcode, char *val, int line_no, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{"pint", top_print},
		{"pop", pop_t},
		{"nop", nop_t},
		{"swap", swap_n},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", divide_nodes},
		{"mul", multiply_nodes},
		{"mod", module_nodes},
		{"pchar", pri_chars},
		{"pstr", pri_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_func(func_list[j].f, opcode, val, line_no, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line_no, opcode);
}

/**
 * call_func - calls the required function
 * @func: pointer to the function that is about to be called
 * @op: string representing opcode
 * @val: string rep a numberic value
 * @line_no: line number for instruction
 * @format: format specifier
 */
void call_func(op_func func, char *op, char *val, int line_no, int format)
{
	stack_t *node;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, line_no);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				error(5, line_no);
		}
		node = build_node(atoi(val) * flag);
		if (format == 0)
			func(&node, line_no);
		if (format == 1)
			add_in_queue(&node, line_no);
	}
	else
		func(&head, line_no);
}
