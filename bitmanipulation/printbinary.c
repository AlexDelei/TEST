#include "main.h"
/**
 *print_binary - binary represantion
 *@n:number
 *
 *
 */
void print_binary(unsigned long int n)
{
	int num_bits;
	int leading_zeros;
	int i;
	unsigned long int mask;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	num_bits = sizeof(n) * 8;
	leading_zeros = 1;

	for (i = num_bits - 1; i >= 0; i--)
	{
		mask = 1UL << i;
		if ((n & mask) != 0)
		{
			putchar('1');
			leading_zeros = 0;
		}
		else if (!leading_zeros)
		{
			putchar('0');
		}
	}
}