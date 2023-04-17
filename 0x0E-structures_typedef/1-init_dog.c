#include "dog.h"
#include <stdio.h>

/**
  * init_dog - Inizialize the structure dog.
  * @d: Structure.
  * @name: Name.
  * @age: Age
  * @owner: Owner..
  * Return: Always 0.
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
