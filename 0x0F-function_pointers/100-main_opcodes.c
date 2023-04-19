#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * main - Print the opcodes.
  * @argc: Number of arguments.
  * @argv: Arguments passed.
  * Return: Integer.
  */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	return (0);
}
