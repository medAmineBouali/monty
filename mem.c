#include "monty.h"


void stack_free(stack_t *stack)
{
    stack_t *next = stack->next;

    while(next)
    {
        stack_t *next = next;
        next = next->next;
        free(next);
    }

    free(stack);
}