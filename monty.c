#include <monty.h>

/**
 * main - Entry point
 * @argc: number of argumensts
 * @argv: arguments
 *
 * Return: nothing
 */

void main(int argc, char *argv[])
{
    stack_t stack;
    instruction_t instr;
	FILE *file;
    size_t current_line;

    if (argc != 2)
    {
        perror("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
	file = fopen(argv[1], 'r');
	if (file == NULL)
	{
		perror("Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
    }
    //main loop
    for (current_line = 1; !feof(file); current_line ++)
    {
        fgets(instr.opcode, 1024, file);
        if (interpret(instr) == 0)
        {
            perror("L%d: unknown instruction %s", current_line, instr.opcode);
            exit(EXIT_FAILURE);
        }
        
    }

}