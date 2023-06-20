/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** task
*/

#include <unistd.h>
int my_putchar(char c);

int my_isneg (int n)
{
    n >= 0 || !n ? my_putchar(80) : my_putchar(78);
    my_putchar('\n');
}
