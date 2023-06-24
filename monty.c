#include "monty.h"

/**
 * main - Entry point
 * @argc: number of argumensts
 * @argv: arguments
 *
 * Return: nothing
 */

int main(int argc, char *argv[])
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    instruction_t instr;
    FILE *file;
    int current_line;

    instr.opcode = NULL;
    instr.f = NULL;
    stack->next = NULL;
    stack->prev = NULL;

    if(!stack)
    {
        fprintf(stderr,"Memory allocation error.\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
        fprintf(stderr,"Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
    }
    
    for (current_line = 1; !feof(file); current_line ++)
    {
        fgets(instr.opcode, 1024, file);
        printf("%s",instr.opcode);

        if (interpret(instr) == 0)
        {
            fprintf(stderr,"L%d: unknown instruction %s", current_line, instr.opcode);
            exit(EXIT_FAILURE);
        }
        instr.f(&stack, current_line);
    }
    fclose(file);
    free(stack);
    return(1);
}