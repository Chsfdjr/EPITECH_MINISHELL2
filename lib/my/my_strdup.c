/*
** EPITECH PROJECT, 2022
** strdup
** File description:
** task01
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    int i = 0;
    char *duplicate = malloc(sizeof(char) * len);

    for (i = 0 ; i < len ; i++)
        duplicate[i] = src[i];
    return duplicate;
}
