#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int estImpair(char c)
{
    int digit = c - '0';
    return digit % 2 != 0;
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void DashInsert(char *str)
{
    size_t len = ft_strlen(str);

    size_t new_len = len;
    for (size_t i = 0; i < len - 1; i++)
    {
        if (estImpair(str[i]) && estImpair(str[i + 1]))
            new_len++;
    }

    char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
    size_t j = 0;

    for (size_t i = 0; i < len; i++)
    {
        new_str[j++] = str[i];
        if (i < len - 1 && estImpair(str[i]) && estImpair(str[i + 1]))
            new_str[j++] = '-';
    }
    new_str[j] = '\0';
    strcpy(str, new_str);
    free(new_str);
}

int main() {
    char str[100] = "454793";
    printf("Chaîne originale : %s\n", str);
    DashInsert(str);
    printf("Chaîne modifiée : %s\n", str);
    return 0;
}
/* DashInsert (str) insère des tirets (-) entre deux nombres impairs dans str.
Par exemple : si str est 454793, la sortie devrait être 4547-9-3.
Ne comptez pas zéro comme impair*/
