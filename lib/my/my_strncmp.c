/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** cmp
*/

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int i = 0;

    while (s1[i] != s1[n] || s2[i] != s2[n]) {
        if (s1[i] == s2[i]) {
            i++;
        } else {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
