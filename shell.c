#include "main.h"

int main(void)
{
    ssize_t bytes_read = 0; 
    size_t buffer_size = 0;
    char *entry = NULL, *arguments[20];
    int counter = 1, exit_status = 0;

    while (1)
    {
        _printp("$ ", 2);
        bytes_read = getline(&entry, &buffer_size, stdin);
        if (bytes_read == -1)
            break;

        if (*entry != '\n')
        {
            fill_args(entry, arguments);
            if (arguments[0] != NULL)
            {
                int exist_status = exist(arguments[0]);
                if (exist_status != 0)
                {
                    int verify_status = verify_path(arguments);
                    if (verify_status == 0)
                        exit_status = exec(arguments), free(entry);
                    else
                    {
                        int builtin_status = verify_blt(arguments, exit_status);
                        if (builtin_status != 0)
                            exit_status = print_not_found(arguments, counter), free(entry);
                    }
                }
                else
                    exit_status = exec(arguments), free(entry);
            }
            else
                free(entry);
        }
        else
            free(entry);

        entry = NULL;
        counter++;
    }

    last_free(entry);
    return exit_status;
}