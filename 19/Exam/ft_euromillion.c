#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_euromillion(void)
{
    int count = 0;
    int i = 1;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    while (i < 12)
    {
        j = i + 1;
        while (j < 13)
        {
            k = 1;
            while (k < 47)
            {
                l = k + 1;
                while (l < 48)
                {
                    m = l + 1;
                    while (m < 49)
                    {
                        n = m + 1;
                        while (n < 50)
                        {
                            o = n + 1;
                            while (o < 51)
                            {
                                ft_putchar('0' + k / 10);
                                ft_putchar('0' + k - k / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + l / 10);
                                ft_putchar('0' + l - l / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + m / 10);
                                ft_putchar('0' + m - m / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + n / 10);
                                ft_putchar('0' + n - n / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + o / 10);
                                ft_putchar('0' + o - o / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + i / 10);
                                ft_putchar('0' + i - i / 10 * 10);
                                ft_putchar(' ');
                                ft_putchar('0' + j / 10);
                                ft_putchar('0' + j - j / 10 * 10);
                                if (i != 11 || j != 12 || k != 46 || l != 47 || m != 48 || n != 49 || o != 50)
                                    write(1, "\t,", 2);
                                ft_putchar('\n');
                                o++;
                                count++;
                            }
                            n++;
                        }
                        m++;
                    }
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    ft_putnbr(count);
}
