#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (2)

int f(int *p)
{
	if (p == NULL)
	{
		return 0;
	}
	++(*p);

	return *p;
}

int main(void)
{
	int *array = malloc(sizeof(int) * SIZE);

	printf("%d\n", f(NULL));

	free(array);
	return 0;
}
