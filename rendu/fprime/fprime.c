#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return (1);
}

void fprime(char *str)
{
	int n = atoi(str)
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");
	while (factor <= n)
	{
		if (n %% factor == 0 && is_prime(factor))
		{
			if (frist == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			frist = 0;
			n = n / factor;
		}
		else
			factor++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}
