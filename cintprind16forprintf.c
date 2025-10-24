#include <inttypes.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(void)
{
	int16_t	i;
	int	j;
	char	k[] = "";

	i = 42;
	j = ft_strlen(k);
	char *fmt = "%" PRId16;
	write(1, "    ", 4);
	printf(fmt, i);
	write(1, "\n\n\n", 3);
	write(1, k, sizeof(k));
	printf(fmt, j);
	write(1, "\n", 1);
	write(1, "\n", 1);

	return (0);
}
