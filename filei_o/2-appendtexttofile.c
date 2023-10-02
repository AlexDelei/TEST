#include "main.h"
/**
 *append_text_to_file - appends text to the end of a file
 *@filename:pointer to our file
 *@text_content: text content
 *Return:1 indicating success
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bw;
	size_t tl;

	if (filename == NULL)
	{
		return (-1);
	}
	/*Opening file for appending*/
	/*open - system call used to open the file specified by filename*/
	if (text_content == NULL || text_content[0] == '\0')
	{
		return (1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}
	tl = strlen(text_content);
	bw = write(fd, text_content, tl);
	if (bw != (ssize_t)tl)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
