#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_TAG_SIZE 10
#define MAX_TAG_COUNT 20

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(const char *src)
{
    char *ret;
    int i = 0;

    ret = (char)malloc((ft_strlen(src) + 1) * sizeof(char));
    if (!ret)
        return (NULL);
    while (src[i])
    {
        ret[i] = src[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 && *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t len;

    len = 0;
    while (src[len] != '\0')
        len++;
    if (!dstsize)
        return (len);
    i = 0;
    while (src[i] && (i + 1 < dstsize))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}

bool isOpenTag(const char *tag)
{
    return tag[1] != '/';
}

bool matchTags(const char *openTag, const char *closeTag)
{
    return ft_strcmp(openTag + 1, closeTag + 2) == 0;
}

bool getTag(const char *str, int *index, char *tag)
{
    int i = 0;

    if (str[*index] != '<')
    {
        return (false);
    }
    while (str[*index] != '>' && str[*index] != '\0')
    {
        tag[i++] = str[(*index)++];
    }
    if (str[*index] == '>')
    {
        tag[i++] = '>';
        (*index)++;
    }
    tag[i] = '\0';
    return (true);
}

void CheckDOM(char *strParam)
{
    int index = 0;
    char tag[MAX_TAG_COUNT][MAX_TAG_SIZE]; // Maximum 20 tags, each 10 characters long
    int count = 0;
    bool almostCorrect = false;
    char wrongTag[MAX_TAG_SIZE];
    char *result;

    while (strParam[index] != '\0')
    {
        char currentTag[MAX_TAG_SIZE];
        if (strParam[index] == '<')
        {
            if (!getTag(strParam, &index, currentTag))
            {
                result = "false";
                printf("%s\n", result);
                return ;
            }
            if (isOpenTag(currentTag))
            {
                ft_strlcpy(tag[count++], currentTag, MAX_TAG_SIZE);
            }
            else
            {
                if (count == 0)
                {
                    if (!almostCorrect)
                    {
                        almostCorrect = true;
                        ft_strlcpy(wrongTag, currentTag, MAX_TAG_SIZE);
                    }
                    else
                    {
                        result = "false";
                        printf("%s\n", result);
                        return ;
                    }
                }
                else
                {
                    if (!matchTags(tag[count - 1], currentTag))
                    {
                        if (!almostCorrect)
                        {
                            almostCorrect = true;
                            ft_strlcpy(wrongTag, currentTag, MAX_TAG_SIZE);
                        }
                        else
                        {
                            result = "false";
                            printf("%s\n", result);
                            return ;
                        }
                    }
                    count--;
                }
            }
        }
        else
        {
            index++;
        }
    }
    if (count > 0)
    {
        if (!almostCorrect)
        {
            almostCorrect = true;
            ft_strlcpy(wrongTag, tag[count - 1], MAX_TAG_SIZE);
        }
        else
        {
            result = "false";
            printf("%s\n", result);
            return ;
        }
    }
    if (almostCorrect)
    {
        result = ft_strdup(wrongTag);
        printf("%s\n", result);
        free(result);
    }
    else
    {
        result = "true";
        printf("%s\n", result);
    }
}

int main(void)
{
    char test1[] = "<div><p>Test</p></div>";
    char test2[] = "<div><p>Test</div></p>";
    char test3[] = "<div><p>Test</p><i>Italic</i></div>";

    CheckDOM(test1);
    CheckDOM(test2);
    CheckDOM(test3);
    return (0);
}
