/*
** EPITECH PROJECT, 2022
** my_lower
** File description:
** lower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    int testing = 0;

    if (str[i] == '\0') {
        return 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= 'a' || str[i] >= 'z') {
            i++;
        } else {
            testing = 1;
            i++;
        }
    }
    if (testing == 1) {
        return 0;
    }
    if (testing == 0) {
        return 1;
    }
}
