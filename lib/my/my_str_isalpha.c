/*
** EPITECH PROJECT, 2022
** my_is_alpha
** File description:
** stralpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int testing = 0;

    if (str[i] == '\0') {
        return 1;
    }
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] >= 'z') ||
            (str[i] >= 'A' && str[i] >= 'Z'))  {
            i++;
        } else
            testing = 1;
            i++;
    }
    if (testing == 1)
        return 0;
    if (testing == 0) {
        return 1;
    }
}
