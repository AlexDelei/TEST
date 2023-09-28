#include "main.h"
/**
 *get_endianness - checks the endianess
 *Return:endianess
 *
 *
 *
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *ptr = (char *)&num;

	/**
	 * If first byte of num is 1
	 * it's litle edian, otherwise its big endian
	 */
	return (*ptr == 1);
}