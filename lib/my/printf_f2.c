/*
** EPITECH PROJECT, 2022
** printf
** File description:
** f2
*/

#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr (char const *str);
void pos_put_float(double nb, int x);
void neg_put_float(double nb, int x);
void my_float(double nb, int x, int temp);
float my_put_float(double nb, int x);

float my_put_float(double nb, int x)
{
    int i = 0;
    if (nb < 0)
        neg_put_float(nb, x);
    if (nb > 0)
        pos_put_float(nb, x);
    else {
        my_put_nbr(0);
        my_putchar('.');
        while (i < x) {
            my_put_nbr(0);
            i = i + 1;
        }
    }
}

void pos_put_float(double nb, int x)
{
    int temp = nb;
    nb = nb - temp;
    my_put_nbr(temp);
    if (x != 0)
        my_float(nb, x, temp);
}

void neg_put_float(double nb, int x)
{
    nb = nb * -1;
    int temp = nb;
    nb = nb - temp;
    my_putchar('-');
    my_put_nbr(temp);
    if (x != 0)
        my_float(nb, x, temp);
}

void my_float(double nb, int x, int temp)
{
    int p = 0;
    int i = 0;
    my_putchar('.');
    while (i < x) {
        nb = nb * 10;
        i = i + 1;
    }
    int dec = nb;
    nb = nb - dec;
    while (p < 2) {
        nb = nb * 10;
        p = p + 1;
    }
    temp = nb;
    if (nb < 50 || nb == 0)
        my_put_nbr(dec);
    else {
        dec = dec + 1;
        my_put_nbr(dec);
    }
}
