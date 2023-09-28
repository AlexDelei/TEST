#include "main.h"
/**
 *clear_bit - removes bit from given index
 *@n:number
 *@index:given point
 *
 *Return:1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		/* Check if the index is out of bounds*/
		return (-1);/*Error: Index is too large*/
	}
	mask = ~(1UL << index);/*Create a mask with the bit at index set to 0*/
	*n = *n & mask;/*Clear the bit at the given index*/
	return (1);/*Successful operation*/
}