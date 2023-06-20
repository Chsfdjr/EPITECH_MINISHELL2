/*
** EPITECH PROJECT, 2022
** pritable
** File description:
** printable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int testing = 0;

    if (str[i] == '\0')
        return 1;
    for (i = 0; str[i] != '\0' ; i++) {
        if (str[i] < 32 || str[i] > 126)
            testing = 1;
    }
    if (testing == 1)
        return 0;
    if (testing == 0)
        return 1;
}
