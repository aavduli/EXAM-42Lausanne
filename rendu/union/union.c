#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check_ascii(char c, int *ascii_tab)
{
	if (ascii_tab[(int)c] == 0)
	{
		ascii_tab[(int)c] = 1;
		ft_putchar(c);
	}
}

void	ft_union(char *str, char *str2)
{
	int ascii_tab[256] = {0};
	int	i = 0;

	while (str[i])
	{
		check_ascii(str[i], ascii_tab);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		check_ascii(str2[i], ascii_tab);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	write(1, "\n", 1);
	return 0;
}
