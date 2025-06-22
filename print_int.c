#include <unistd.h>
#include "main.h"

/**
 * print_int - Prints an integer to stdout
 * @n: The integer to print
 *
 * Description: Handles both positive and negative integers.
 * Uses write to print digit by digit without recursion.
 *
 * Return: The number of characters printed
 */
int print_int(int n)

{
	unsigned int num;
	int count = 0;
	int div = 1;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		c = (num / div) % 10 + '0';
		count += write(1, &c, 1);
		div /= 10;
	}

	return (count);
}
