/*
** EPITECH PROJECT, 2022
** power rev
** File description:
** task04
*/

int av_to_int(char *av)
{
    int result = 0;
    int sign = 1;
    if (av[0] == '-') {
        sign = -1;
        av++;
    }
    while (*av != '\0') {
        int digit = *av - '0';
        result = result * 10 + digit;
        av++;
    }
    return sign * result;
}
