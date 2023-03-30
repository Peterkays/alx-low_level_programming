#include <stdio.h>
/**
 * print_buffer - the buffer function
 *
 * @b: store of value
 * @size: store of value
 * Return: always 0
 */

void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x ", i);

	{
		for (j = 0; j < 10 && i + j < size; j++)
			printf("%02x ", b[i + j]);
		for (; j < 10; j++)
			printf(" ");
		for (j = 0; j < 10 && i + j < size; j++)
			printf("%c", b[i + j] >= ' ' && b[i + j] <= '~' ? b[i + j] : '.');
	}
	printf("\n");
	}
}
