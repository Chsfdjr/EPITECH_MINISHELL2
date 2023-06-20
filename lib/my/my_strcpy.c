/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** task01
*/
#include <unistd.h>

void my_putchar(char c);
int my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}
