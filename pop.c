#include "monty.h"

/**
 * f_pint - entry point
 * @head: ckddok
 * @counter: deds
 * Return: entry point
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		cleanup_resources(head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

