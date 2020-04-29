#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isalphanum(char base)
{

		if ((base < 'a' || base > 'z') || (base < 'A' || base > 'Z'))
			return (0);
		else if (base < '0' ||  base > '9')
			return (0);
	return (1);
}

int check_base(char *base)
{
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	while (i < size - 1)
	{

		j = i + 1;

		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
}

int	ft_atoi_base(char *str, char *base)
{

}