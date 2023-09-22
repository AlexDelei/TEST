#include "main.h"
/**
 * _getenv - Get the content of a global variable
 * @global_var: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_getenv(char *global_var)
{
    if (global_var == NULL || environ == NULL)
        return NULL;

    int i = 0;
    const char cutter[] = "=";
    char *env_tok, *env_tok_dup;

    while (environ[i] != NULL)
    {
        char *envdup = _strdup(environ[i]);
        env_tok = strtok(envdup, cutter);

        if (_strcmp(env_tok, global_var) == 0)
        {
            env_tok = strtok(NULL, cutter);
            env_tok_dup = _strdup(env_tok);
            free(envdup);
            return env_tok_dup;
        }

        free(envdup);
        i++;
    }

    return NULL;
}