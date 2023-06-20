/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int add_charac = 0;
    int i = my_strlen(dest);
    while (src[add_charac] != '\0') {
        dest[i] = src[add_charac];
        i++;
        add_charac++;
    }
    return dest;
}
