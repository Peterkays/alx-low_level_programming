#include <stdio.h>
/**
 * main - entry point
 *
 * Return: alway returns 0
 *
 */
int main(void)
{
	char a;

	for (a = 'a'; a <= 'z' ; a++)
	{
		if (a == 'e' || a == 'q')
		{
			continue;
		}
		putchar(a);
	}
	putchar('\n');
	return (0);
}
