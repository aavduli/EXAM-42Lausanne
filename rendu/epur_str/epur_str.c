#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void epur_str(char *str)
{
	int i = 0;
	int space = 0;

	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (space && str[i])
			write(1, " ", 1);
		while(!is_space(str[i]) && str[i])
		{
			write(1, &str[i], 1);
			i++;
			space = 1;
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		epur_str(av[1]);
	}
	write(1, "$", 1);
	write(1, "\n", 1);
	return 0;
}
