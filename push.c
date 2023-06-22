#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: lsdjd
 * @counter: ffddf
 * Return: void
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;
	char *endptr;

	if (bus.arg == NULL || !is_valid_integer(bus.arg))
	{
		print_push_usage_error(counter);
		cleanup_resources(head);
		exit(EXIT_FAILURE);
	}

	n = strtol(bus.arg, &endptr, 10);
	if (*endptr != '\0')
	{
		print_push_usage_error(counter);
		cleanup_resources(head);
		exit(EXIT_FAILURE);
	}

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * is_valid_integer - checks if a string represents a valid integer
 * @str: string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * print_push_usage_error - prints the usage error message for push command
 * @counter: line number
 *
 * Return: no return
 */
void print_push_usage_error(unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
}

/**
 * cleanup_resources - performs cleanup tasks in case of error
 * @head: stack head
 *
 * Return: no return
 */
void cleanup_resources(stack_t **head)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
}

