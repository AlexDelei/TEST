#include "main.h"
/**
 *get_bit - retrieves value of a bit at index given
 *@n:the number
 *@index:point given
 *Return:bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(n) * 8)
	{
		return (-1);
	}

	mask = 1UL << index;
	return ((n & mask) != 0);
}