#include "monty.h"


/**
 * cleanup_resources - performs cleanup tasks in case of error
 * @head: stack head
 *
 * Return: no return
 */
void cleanup_resources(FILE *file, stack_t **head)
{
	fclose(file);
	free_stack(*head);
}

