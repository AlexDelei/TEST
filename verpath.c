#include "main.h"
/**
 * verify_path - Verify if the first command can be executed
 * @arguments: Array of entries by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int verify_path(char **arguments)
{
    char *path_env = _getenv("PATH");
    if (path_env == NULL)
        return -1;

    char *path = _strdup(path_env);
    free(path_env);

    char *dir = strtok(path, ":");
    while (dir != NULL)
    {
        char *command_path = append_command(dir, arguments[0]);
        int exist_stat = exist(command_path);
        free(command_path);

        if (exist_stat == 0)
        {
            free(path);
            arguments[0] = append_command(dir, arguments[0]);
            return 0;
        }

        dir = strtok(NULL, ":");
    }

    free(path);
    return -1;
}