/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** strncat
*/

int my_strlen (char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int add_charac = 0;
    int i = my_strlen(dest);
    while (add_charac != nb) {
        dest[i] = src[add_charac];
        i++;
        add_charac++;
    }
    if (nb > i) {
        dest[i] = src[i];
        return dest;
    } else {
        return dest;
    }
}
