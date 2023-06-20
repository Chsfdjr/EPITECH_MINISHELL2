/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

char **mod_env_2(char **env, int len_tab, char **buffer)
{
    char **env_cpy = NULL;

    env_cpy = malloc(sizeof(char *) * (len_tab + 2));
    for (int o = 0 ; o != len_tab ; o++)
        env_cpy[o] = env[o];
    env_cpy[len_tab] = malloc(sizeof(char) * my_strlen(buffer[1]) + 1);
    env_cpy[len_tab] = buffer[1];
    env_cpy[len_tab + 1] = NULL;
    return env_cpy;
}

int check_mod_env(char **buffer)
{
    int len_buf = 0;

    while (buffer[len_buf] != NULL)
        len_buf++;
    if (check_arg_env(buffer, len_buf) == 84) {
        my_printf("setenv: Too many arguments.\n");
        return 84;
    }
    return len_buf;
}

int nb_of_char(char *str, char charc)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == charc)
            nb++;
        i++;
    }
    return nb;
}
