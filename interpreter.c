#include "monty.h"

/**
 * interpret - ffj
 * @instr: instruction stuct.
 * 
 * Return: 1 on success.
 *        0 when function fails or instructions are invalide.
 */
size_t interpret(instruction_t instr)
{
    char op = strtok(instr.opcode, ' ');
    char num;
    if (strcmp("push", op))
    {
        num = strtok(NULL, ' ');
        if(strtok(NULL, ' ') == NULL && isdigit(num))
        {
             instr.f = &f_push;
        }
        else
            return (0);
    } else
    {
        if(strtok(NULL, ' ') == NULL)
        {
            if (strcmp("pall", op))
                instr.f = &f_pall;
            if (strcmp("pint", op))
                instr.f = &f_pint;
        } else
            return (0);
    }
}