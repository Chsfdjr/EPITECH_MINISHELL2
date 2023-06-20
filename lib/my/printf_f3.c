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
int put_in_hexa(int nb);
int put_in_octa(int nb);
int disp_xm(va_list list_printf, int x);
int disp_x(va_list list_printf, int x);

int put_in_octa(int nb)
{
    int octa = 0;
    int count = 0;

    while (nb != 0) {
        count++;
        if (octa == 77) {
            octa = 99;
            count = 0;
        }
        if (count > 7) {
            octa = octa + 2;
            count = 0;
        }
        if (octa == 177)
            return octa;
        else
            octa++;
        nb--;
    }
    my_put_nbr(octa);
}

int put_in_hexa(int nb)
{
    char nbhexa0 = '0';
    char nbhexa1 = '0';

    for (int count = nb ; count != 0 ; count--) {
        nbhexa1++;
        if (nbhexa1 == ':')
            nbhexa1 = 'A';
        if (nbhexa1 == 'G') {
            nbhexa1 = '0';
            nbhexa0 ++;
        }
        if (nbhexa0 == ':')
            nbhexa0 = 'A';
    }
    my_putchar(nbhexa0);
    my_putchar(nbhexa1);
    return 0;
}

int put_in_minihexa(int nb)
{
    char nbhexa0 = '0';
    char nbhexa1 = '0';

    for (int count = nb ; count != 0 ; count--) {
        nbhexa1++;
        if (nbhexa1 == ':')
            nbhexa1 = 'a';
        if (nbhexa1 == 'g') {
            nbhexa1 = '0';
            nbhexa0 ++;
        }
        if (nbhexa0 == ':')
            nbhexa0 = 'a';
    }
    my_putchar(nbhexa0);
    my_putchar(nbhexa1);
    return 0;
}

int disp_xm(va_list list_printf, int x)
{
    put_in_hexa(va_arg(list_printf,int));
}

int disp_x(va_list list_printf, int x)
{
    put_in_minihexa(va_arg(list_printf,int));
}
