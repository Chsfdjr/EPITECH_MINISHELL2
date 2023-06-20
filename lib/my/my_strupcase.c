/*
** EPITECH PROJECT, 2022
** upcase
** File description:
** upcase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 97) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
