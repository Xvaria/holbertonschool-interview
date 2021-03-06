#include "palindrome.h"

/**
 * is_palindrome - check whether or not a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int count, i;
	char numb[19];

	count = sprintf(numb, "%ld", n);
	for (i = 0; i < count / 2; i++)
	{
		if (numb[i] != numb[count - 1 - i])
			return 0;
	}
	return 1;
}
