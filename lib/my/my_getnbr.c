/*
** EPITECH PROJECT, 2022
** nex my_getnbr
** File description:
** sss
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int digit = 0;
    int i = 0;

    for (;str[i] < '0' || str[i] > '9'; i++) {
        if (str[i] == '\0')
            return -99999;
    }
    if (str[i - 1] == '-')
        sign = -1;
    for (;str[i] != '\0'; i++) {
        digit = str[i] - '0';
        result = result * 10 + digit;
    }
    return sign * result;
}
