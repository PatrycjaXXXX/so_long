#include <stdlib.h>
#include <stdio.h>


int main(int ac, char **av)
{
	if (ac != 3)
		return (printf("\n"), 0);
	int a = atoi(av[1]);
	int b = atoi(av[2]);
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return (printf("%i\n", a), 0);
}
