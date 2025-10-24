#include <stdio.h>

size_t ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void AlphabetSoup(char str[])
{
    size_t n = ft_strlen(str);
    char temp;

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j+1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    char str1[] = "hello";
    char str2[] = "Remy";

    printf("Chaîne originale : %s\n", str1);
    AlphabetSoup(str1);
    AlphabetSoup(str2);
    printf("Chaîne triée : %s\n", str1);
    printf("%s\n", str2);
    return (0);
}

/* AlphabetSoup (str) prend le paramètre de chaîne str en cours de passage et renvoie
la chaîne avec les lettres dans l'ordre alphabétique (c'est-à-dire que hello devient
ehllo). Supposons que les chiffres et les symboles de ponctuation ne seront pas inclus
dans la chaîne.*/
