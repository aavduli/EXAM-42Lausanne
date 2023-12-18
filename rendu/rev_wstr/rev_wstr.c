#include <unistd.h>

int	is_sep(char c)
{
	return (c = ' ' || c = '\t');
}

void	rev_wstr(char *str)
{
	int	start;
	int	end;
	int	i = 0;
	int first = 0;

	while (str[i])
		i++;
	while (i >= 0)
	{
		end = i;
		while (!is_sep[str[i]])
			i--;
		start = i + 1;
		while(start <= end)
		{
			write(1, &str[start], 1);
			start++;
			if (!first)
			{
				write(1, " ", 1);
				first = 1;
			}
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_wstr(av[1]);
	}
	write(1, "\n", 1);
	return 0;
}
