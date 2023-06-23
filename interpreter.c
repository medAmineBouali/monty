#include "monty.h"
int num = 0;
/**
 * interpret - ffj
 * @instr: instruction stuct.
 * 
 * Return: 1 on success.
 *        0 when function fails or instructions are invalide.
 */
size_t interpret(instruction_t instr)
{
    char *op = strtok(instr.opcode, " ");
    char *n;
    if (strcmp("push", op) == 0)
    {
        n = strtok(NULL, " ");
        if(strtok(NULL, " ") == NULL && isdigit(*n))
        {
            instr.f = &f_push;
            num = atoi(n);
        }
        else
            return (0);
    } else
    {
        if(strtok(NULL, " ") == NULL)
        {
            if (strcmp("pall", op) == 0)
                instr.f = &f_pall;
            if (strcmp("pint", op) == 0)
                instr.f = &f_pint;
        } else
            return (0);
    }
    return (1);
}