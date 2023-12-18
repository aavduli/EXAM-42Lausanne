
#include <stdio.h>


int is_space(char c)
{
	return (c <= 32);
}

int is_valid(char c, int base)
{
	char digits[16] = "0123456789ABCDEF";
	char digits2[16] = "0123456789abcdef";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
		return (0);
}

int convert(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F' )
		return (c - 'A' + 10);
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int signe = 1;
	int result = 0;

	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while(is_valid(str[i], str_base))
	{
		result = result * str_base + convert(str[i]);
		i++;
	}
	return (result * signe);
}

int main() {
    // Test avec différentes chaînes et bases
    const char *str1 = "10"; // Base 10
    const char *str2 = "A";  // Base 16
    const char *str3 = "1010"; // Base 2
    const char *str4 = "7F"; // Base 16
    const char *str5 = "--1A"; // Base 16
    const char *str6 = "+1A"; // Base 16

    printf("'%s' en base 10 est %d\n", str1, ft_atoi_base(str1, 10));
    printf("'%s' en base 16 est %d\n", str2, ft_atoi_base(str2, 16));
    printf("'%s' en base 2 est %d\n", str3, ft_atoi_base(str3, 2));
    printf("'%s' en base 16 est %d\n", str4, ft_atoi_base(str4, 16));
    printf("'%s' en base 16 est %d\n", str5, ft_atoi_base(str5, 16));
    printf("'%s' en base 16 est %d\n", str6, ft_atoi_base(str6, 16));

    return 0;
}
