#include "main.h"
/**
 *read_textfile - reads a text file and prints to stdout
 *@filename:the file
 *@letters:number of letters to print
 *
 *Return:total bytes read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t br, bw;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buffer = (char *)malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	br = read(fd, buffer, letters);
	bw = write(STDOUT_FILENO, buffer, br);
	if (bw == -1 || bw != br)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	free(buffer);
	return (br);
}
