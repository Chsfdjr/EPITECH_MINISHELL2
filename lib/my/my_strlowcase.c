/*
** EPITECH PROJECT, 2022
** upcase
** File description:
** upcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}
