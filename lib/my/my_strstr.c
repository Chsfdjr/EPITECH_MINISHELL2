/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** task05
*/

#include <stdio.h>

int my_strlen_2 (char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int i_2 = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[i_2]) {
            i_2++;
        } else {
            i_2 = 0;
        }
        i++;
        if (to_find[i_2] == '\0') {
            i = i - i_2;
            return &str[i];
        }
    }
}
