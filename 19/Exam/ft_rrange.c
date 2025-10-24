#include <stdlib.h>

#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int step = 1;
	int n = end - start;

	if (n < 0)
		(n *= -1);
	n++;

	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		if (start < end)
			step = -1;
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}

int main(void)
{
    int i = -4;
    int j = 4;
    int l = 0;
    int *range;
    int length = abs(i - j) + 1;
    int k = 0;

    range = ft_rrange(i, j);
    if (range == NULL)
        return (1);
    while (k < length)
    {
        printf("%d ", range[k]);
        k++;
    }
    printf("\n");
    free(range);
    return (0);
}
