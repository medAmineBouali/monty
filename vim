#include "monty.h"

/**
 * f_pall - entry point
 * @head: pedeme
 * @counter: djejde
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

