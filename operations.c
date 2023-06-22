#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: lsdjd
 * @counter: ffddf
 * Return: void
 */
void f_push(stack_t **head, unsigned int counter)
{
	
}

/**
 * f_pall - entry point
 * @head: xlledeje
 * @counter: sdlske
 * Return: void
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

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
