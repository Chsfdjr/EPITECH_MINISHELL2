/*
** EPITECH PROJECT, 2022
** upper
** File description:
** upper
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int testing = 0;

    if (str[i] == '\0') {
        return 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] >= 'Z') {
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
