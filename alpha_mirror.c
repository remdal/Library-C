#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - (str[i] - 'a');
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ('Z' + 'A') - str[i];
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
