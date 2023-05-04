#include "main.h"

/**
  * get_endianness - Check if the system is little or big endianness.
  *
  * Return: 1 if is little, and 0 if is big.
  */

int get_endianness(void)
{
	int i = 1;

	if (*(char *)&i == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
