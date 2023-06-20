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
int disp_charac(va_list list_printf, int x);
int disp_str(va_list printf, int x);
int disp_int(va_list printf, int x);
int disp_pourcentage(va_list printf, int x);
int disp_u(va_list printf, int x);
int disp_x(va_list printf, int x);
int disp_xm(va_list printf, int x);
int disp_o(va_list printf, int x);
int put_in_hexa(int nb);
int put_in_minihexa(int nb);
int put_in_octa(int nb);

int disp_charac(va_list list_printf, int x)
{
    my_putchar(va_arg(list_printf,int));
}

int disp_str(va_list list_printf, int x)
{
    my_putstr(va_arg(list_printf,const char *));
    return 0;
}

int disp_int(va_list list_printf, int x)
{
    my_put_nbr(va_arg(list_printf,int));
    return 0;
}

int disp_pourcentage(va_list list_printf, int x)
{
    my_putchar('%');
}
