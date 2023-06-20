/*
** EPITECH PROJECT, 2022
** printf_1
** File description:
** charac
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int disp_o(va_list list_printf, int x);
int my_putstr (char const *str);
void my_put_float(double nb, int x);
int disp_e(va_list list_printf, int x);
int disp_f(va_list list_printf, int x);
int disp_fm(va_list list_printf, int x);
int put_in_octa(int nb);

int disp_o(va_list list_printf, int x)
{
    put_in_octa(va_arg(list_printf,int));
}

int disp_f(va_list list_printf, int x)
{
    double nb = va_arg(list_printf, double);
    if (nb != nb)
        my_putstr("nan");
    if (nb == 1.0 / 0.0)
        my_putstr("inf");
    if (nb == -1.0 / 0.0)
        my_putstr("-inf");
    else
        my_put_float(nb, x);
}

int disp_fm(va_list list_printf, int x)
{
    double nb = va_arg(list_printf, double);
    if (nb != nb)
        my_putstr("NAN");
    if (nb == 1.0 / 0.0)
        my_putstr("INF");
    if (nb == -1.0 / 0.0)
        my_putstr("-INF");
    else
        my_put_float(nb, x);
}
