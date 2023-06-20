/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02
*/

char *my_revstr (char *str)
{
    int i = 0;
    int i_2 = 0;
    char stock;
    while (str[i] != '\0') {
        i = i + 1;
    }
    --i;
    while (i_2 < i) {
        stock = str[i];
        str[i] = str[i_2];
        str[i_2] = stock;
        i_2++;
        i--;
    }
    return str;
}
