#include "main.h"
/**
 *binary_to_uint - converts binary to unint
 *@b:string
 *
 *Return: result
 */
unsigned int binary_to_uint(const char *b)
{
	char current_char;
	unsigned int result = 0;
	int index = 0;

	if (b == NULL)
		return (0);
	while (b[index] != '\0')
	{
		current_char = b[index];
		if (current_char != '0' && current_char != '1')
			return (0);

		result = (result << 1) + (current_char - '0');
		index++;
	}

	return (result);
}