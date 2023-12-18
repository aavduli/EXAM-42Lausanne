#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}
int	ft_wordlen(char *str)
{
	int i = 0;

	while(!is_space(str[i]) && str[i])
		i++;
	return (i);
}

int count_word(char *str)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i])
    {
        if (!is_space(str[i]) && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (is_space(str[i]))
        {
            in_word = 0;
        }
        i++;
    }
    return (count);
}

char	**ft_split(char *str)
{
	char **split;
	int i = 0;
	int j = 0;
	int k = 0;

	split = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	if(!split)
		return 0;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			int len = ft_wordlen(&str[i]);
			split[k] = (char *)malloc(sizeof(char) * (len + 1));
			j = 0;
			while (j < len)
				split[k][j++] = str[i++];
			split[k++][j] = '\0';
		}
		else
		i++;
	}
	split[k] = NULL;
	return(split);
}

void	ft_rotstring(char	**split)
{
	int i = 0;
	int k = 1;

	while(split[k])
	{
		i = 0;
		while(split[k][i])
		{
			write(1, &split[k][i], 1);
			i++;
		}
		write(1, " ", 1);
		k++;
	}
	i = 0;
	while (split[0][i])
	{
		write(1, &split[0][i], 1);
		i++;
	}
}
int main(int ac, char **av)
{
	if(ac == 2)
	{
		char **split = ft_split(av[1]);
		ft_rotstring(split);
	}
	write(1, "\n", 1);
	return 0;
}
