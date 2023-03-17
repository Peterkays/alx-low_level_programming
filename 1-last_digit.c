#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 *
 *
 * Return: always return 0
 *
 */
int main(void)
{
	int n;
	int lstn;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lstn = n % 10;

	if (lstn > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, lstn);
	}
	else if (lstn == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, lstn);
	}
	else
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, lstn);
	}
	return (0);
}
