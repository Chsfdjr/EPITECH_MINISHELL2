/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

void cd_env(char **env, char *line, char *buf)
{
    int len_tab = 0;
    int first_len = my_strlen(line);

    for (len_tab = 0 ; env[len_tab] != NULL ; len_tab++) {
        if (my_strncmp(env[len_tab], line, first_len) == 0) {
            env[len_tab] = malloc(sizeof(char) * my_strlen(buf) + 1);
            env[len_tab] = add_to_buffer(line, buf, 2);
            return;
        }
    }
}

int check_arg_env(char **tab, int len_tab)
{
    if (len_tab > 3)
        return 84;
    if (len_tab == 3)
        return 2;
    if (len_tab == 2) {
        if (found_charc_from_buffer(tab[1], '=') == 0)
            return 1;
        else
            return 0;
    }
}

int removefromenv(char *env, char **env_cpy, char **buffer, int i)
{
    int o = 0;
    int e = 0;
    int test = 0;

    for (o = 1 ; buffer[o] != NULL ; o++) {
        if (my_strncmp(buffer[o], env, my_strlen(buffer[o])) == 0)
            test = 1;
    }
    if (test == 0) {
        env_cpy[i] = env;
        i++;
    }
    return i;
}

char **removeinenv(char **env, char **buffer)
{
    int o = 0;
    int i = 0;
    int len_tab = 0;
    int nb_arg = 0;
    char **env_cpy = NULL;

    while (env[len_tab] != NULL)
        len_tab++;
    for (int count = 1 ; buffer[count] != NULL ; count++)
        nb_arg++;
    env_cpy = malloc(sizeof(char *) * (len_tab + 1));
    for (env = env ; *env ; *env++)
        i = removefromenv(*env, env_cpy, buffer, i);
    env_cpy[i] = NULL;
    return env_cpy;
}
