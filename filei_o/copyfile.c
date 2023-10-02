#include "main.h"
/**
 *copyFile - copying function
 *@file_from: source file
 *@file_to: destination file
 */
void copyFile(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;
	/*Open the source file for reading*/
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		handleError("Error: Can't read from file %s\n", 98);
	}
	/*Create or open the destination file for writing, with appropriate permissions*/
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		handleError("Error: Can't write to file %s\n", 99);
	}
	/*Copy the contents from file_from to file_to*/
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			handleError("Error: Can't write to file %s\n", 99);
		}
	}
	if (bytes_read == -1)
	{
		handleError("Error: Can't read from file %s\n", 98);
	}
	/*Close the file descriptors*/
	if (close(fd_from) == -1)
	{
		handleError("Error: Can't close fd %d\n", 100);
	}
	if (close(fd_to) == -1)
	{
		handleError("Error: Can't close fd %d\n", 100);
	}
}
