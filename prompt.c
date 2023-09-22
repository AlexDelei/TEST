#include "main.h"
/**
 * _printp - Prints the prompt in the standard output
 * @prompt: Pointer to the string to be printed
 * @size: Length of the prompt
 * Return: 0 if success or -1 if fails
 */
int _printp(const char *prompt, unsigned int size)
{
    if (isatty(STDOUT_FILENO))
    {
        int written = fwrite(prompt, sizeof(char), size, stdout);
        if (written == -1)
            return -1;
    }
    return 0;
}