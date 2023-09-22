#include "main.h"
/**
 * verify_blt - Verify if the input is a builtin
 * @arguments: Pointer to the array of arguments
 * @exit_stat: Current exit status
 * Return: -1 if the command is not a builtin, 0 if it is
 */
int verify_blt(char **arguments, int exit_stat)
{
    char *builtins[] = {
        "exit",
        "env"
    };
    int num_builtins = sizeof(builtins) / sizeof(char *);
    int i;

    for (i = 0; i < num_builtins; i++)
    {
        if (_strcmp(arguments[0], builtins[i]) == 0)
            break;
    }

    if (i == num_builtins)
        return -1;

    if (_strcmp(builtins[i], "exit") == 0)
    {
        free(arguments[0]);
        exit(exit_stat);
    }
    else if (_strcmp(builtins[i], "env") == 0)
    {
        if (environ == NULL)
            return 0;

        char **env_ptr = environ;
        while (*env_ptr)
        {
            printf("%s\n", *env_ptr);
            env_ptr++;
        }
    }

    return 0;
}