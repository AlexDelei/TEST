#include "main.h"
/**
 *create_file - creates a file and adds text in it
 *@filename:pointer to our file
 *@text_content:pointer to text
 *
 *Return:1 if successful
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bw;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (text_content != NULL)
	{
		bw = write(fd, text_content, strlen(text_content));
		if (bw == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
