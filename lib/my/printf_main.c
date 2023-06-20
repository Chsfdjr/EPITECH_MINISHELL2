/*
** EPITECH PROJECT, 2022
** minip_main.c
** File description:
** projet miniprinft
*/

#include <stdarg.h>

int disp_charac(va_list list_printf, int x);
int disp_int(va_list list_printf, int x);
int disp_pourcentage(va_list list_printf, int x);
int disp_str(va_list list_printf, int x);
void my_putchar(char c);
int my_put_nbr(int nb);
int precision(const char *format, int c);
int disp_o(va_list list_printf, int x);
int disp_x(va_list list_printf, int x);
int disp_xm(va_list list_printf, int x);
int disp_f(va_list list_printf, int x);
int disp_fm(va_list list_printf, int x);
void pos_put_float(double nb, int x);
void neg_put_float(double nb, int x);
int my_printf_findflag(const char *format,  int c, va_list list_printf);
int my_getnbr(char const *str);
int new_c(const char *format, int c);

int precision(const char *format, int c)
{
    int x = 0;

    if (format[c + 1] == '0') {
        x = 6;
        return x;
    } else
        for (; format[c] != '\0' ; c++) {
            return x;
        }
}

int new_c(const char *format, int c)
{
    for (; format[c] != '\0' ; c++) {
        if (format[c + 1] <= 48 || format[c + 1] >= 57)
            return c;
    }
}

int my_printf_findflag(const char *format, int c, va_list list_printf)
{
    char flag[10] = "cid%soxXfF";
    int n_flag = 0;
    int x;

    int (*tab_ftc[10])(va_list,int) =
        {disp_charac, disp_int, disp_int, disp_pourcentage,
        disp_str, disp_o, disp_x, disp_xm, disp_f, disp_fm};

    if (format[c + 1] == '.') {
        x = precision(format,c);
        c = new_c(format, c);
    }
    for (n_flag = 0 ; flag[n_flag] != '\0' ; n_flag ++) {
        if (format[c + 1] == flag[n_flag]) {
            (tab_ftc[n_flag])(list_printf,x);
            c = c + 1;
            break;
        }
    }
    return c;
}

int my_printf(const char *format, ...)
{
    char flag[10] = "cid%soxXfF";
    int n_flag = 0;
    int (*tab_ftc[10])(va_list, int) =
        {disp_charac, disp_int, disp_int, disp_pourcentage,
        disp_str, disp_o, disp_x, disp_xm, disp_f, disp_fm};
    va_list list_printf;
    va_start(list_printf, format);
    for (int c = 0; format[c] != '\0' ; c++) {
        if (format[c] == '%')
            c = my_printf_findflag(format, c, list_printf);
        else
            my_putchar(format[c]);
    }
    va_end(list_printf);
    return 0;
}
