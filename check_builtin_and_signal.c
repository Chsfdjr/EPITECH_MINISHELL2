/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

void controller(int signo)
{
    if (signo == SIGTSTP) {
        my_printf("kill susp\n");
    }
    if (signo == SIGINT) {
        my_printf("ctrl + d\n");
    }
}

void check_signal(void)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
}

char **check_builtin(char *buf, char **env, folder_stat *dir_stat)
{
    char **tab = my_str_to_word_array(buf, "\n \t");
    if (tab == NULL || tab[0] == NULL)
        return env;
    if (my_strcmp(tab[0], "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
    if (my_strcmp(tab[0], "env") == 0) {
        printenv(env);
        return env;
    }
    if (my_strcmp(tab[0], "unsetenv") == 0) {
        if (tab[1] == NULL)
            my_printf("unsetenv: Too few arguments.\n");
        else
            env = removeinenv(env, tab);
        return env;
    }
    env = check_builtin_2(tab, env, dir_stat);
    return env;
}

char **check_builtin_2(char **tab, char **env, folder_stat *dir_stat)
{
    if (my_strcmp(tab[0], "setenv") == 0) {
        if (tab[1] == NULL)
            printenv(env);
        else
            env = mod_env(tab, env, 1);
        return env;
    }
    if (my_strcmp(tab[0], "cd") == 0) {
        cd_builtin(tab, dir_stat, env);
        dir_stat->current_dir = currentfile();
        return env;
    }
    execute_print(tab, env, 0, dir_stat);
    return env;
}
