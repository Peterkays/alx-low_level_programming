#include <stdio.h>

/**
  * print_name - Structure.
  * @name: Name.
  * @f: function.
  */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	{
		return;
	}

	f(name);
}
