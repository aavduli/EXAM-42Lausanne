#include <stdio.h>
#include <stdlib.h>

int	is_blank(char c)
[
	if (c <= 32)
		return 1;
	return 0;
]

int	is_valid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return 0;
}

int	ft_atoi_base(const char *str, int base)
{
	int result;
	int signe = 1;
	int i = 0;

	result = 0;
	while(is_blank(str[i]))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while(is_valid(str[i], base))
	{
		result = result * base + value_of(str[i]);
		i++;
	}
	return (result * signe);
}
