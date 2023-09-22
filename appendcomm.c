#include "main.h"
/**
 * append_command - Concatenates an input with paths in global variable PATH
 * @dir_path: directory string to be appended with the command
 * @command: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *append_command(char *dir_path, char *command)
{
    if (dir_path == NULL || command == NULL)
        return NULL;

    int len1 = _strlen(dir_path);
    int len2 = _strlen(command);

    // Allocate memory for the concatenated path (+1 for the '/' and +1 for the null terminator)
    char *command_path = (char *)malloc(len1 + len2 + 2);

    if (command_path == NULL)
        return NULL;

    int a, b;
    for (a = 0; a < len1; a++)
        command_path[a] = dir_path[a];

    if (dir_path[a - 1] != '/')
    {
        command_path[a] = '/';
        a++;
    }

    for (b = 0; b < len2; b++)
        command_path[a + b] = command[b];

    command_path[a + b] = '\0';

    return command_path;
}