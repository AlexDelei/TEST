#include "main.h"

/**
 * handle_error - Error handling function
 * @error_code: The error code to print
 * @file_path: The file path associated with the error
 */
void handle_error(int error_code, const char *file_path)
{
	switch (error_code)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		break;
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_path);
		break;
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_path);
		break;
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", file_path);
		break;
	case 95:
		dprintf(STDERR_FILENO, "Error: Can't set permissions for %s\n", file_path);
		break;
	default:
		dprintf(STDERR_FILENO, "Unknown error code: %d\n", error_code);
	}
	exit(error_code);
}
