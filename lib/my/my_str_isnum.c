/*
** EPITECH PROJECT, 2022
** my_is_num
** File description:
** stralpha
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int testing = 0;

    if (str[i] == '\0') {
        return 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            i++;
        } else {
            i++;
            testing = 1;
        }
    }
    if (testing == 0) {
        return 1;
    }
    if (testing == 1) {
        return 0;
    }
}
