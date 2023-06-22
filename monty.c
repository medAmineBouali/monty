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
    stack_t *stack = malloc(sizeof(stack_t));
    instruction_t *instr = malloc(sizeof(instruction_t));
	FILE *file;
    int current_line;
 
    if (argc != 2)
    {
        perror("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error: ");
        printf("Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
    }
    for (current_line = 1; !feof(file); current_line ++)
    {
        fgets(instr->opcode, 1024, file);
        if (interpret(*instr) == 0)
        {
            perror("L");
            printf("%d: unknown instruction %s", current_line, instr->opcode);
            exit(EXIT_FAILURE);
        }
        printf("%d\n",num);
        instr->f(&stack, current_line);
    }
    return(1);
}