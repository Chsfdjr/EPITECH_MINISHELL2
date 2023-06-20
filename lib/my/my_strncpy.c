/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** task01
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int init = 0;

    while (init != n) {
        dest[i] = src[i];
        i++;
        init++;
    }
    if (n > i) {
        dest[i] = src[i];
        return dest;
    } else {
        return dest;
    }
}
