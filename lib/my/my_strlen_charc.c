/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** task03
*/

#include <unistd.h>

int my_strlen_charc(char const *str, char charc)
{
    int i = 0;

    while (str[i] != charc)
        i = i + 1;
    return i;
}
