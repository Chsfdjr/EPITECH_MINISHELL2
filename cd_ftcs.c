/*
** EPITECH PROJECT, 2022
** header
** File description:
** minishell
*/

#include "include/minishell.h"

char *found_envline(char **env, char *line)
{
    char *home = NULL;
    int len = my_strlen(line);
    int i = 0;
    int i_2 = 0;

    for (i = 0 ; env[i] != NULL ; i++) {
        if (my_strncmp(env[i] , line , len) == 0)
            break;
    }
    if (env[i] + len == NULL)
        return NULL;
    return env[i] + len;
}

int check_root(char *filepath)
{
    for (int i = 0 ; filepath[i] != '\0' ; i++) {
        if (filepath[i] != ' ')
            return -1;
    }
    return 0;
}

int check_cd_builtin_2(char **file, struct stat desc)
{
    int i = lstat(file[1], &desc);

    if (i == -1 || access(file[1], F_OK) != 0) {
        my_printf("cd: no such file or directory: %s\n", file[1]);
        return 1;
    }
}

int check_cd_builtin(char **file, folder_stat *dir_s, char **env)
{
    int i = 0;
    struct stat d;
    char *home = found_envline(env, "HOME=");

    while (file[i] != NULL)
        i++;
    if (i == 1) {
        dir_s->last_dir = currentfile();
        chdir(home);
        dir_s->current_dir = currentfile();
        cd_env(env, "PWD=", dir_s->current_dir);
        return 1;
    }
    if (i > 2) {
        my_printf("cd: too many arguments\n");
        return 1;
    }
    if (my_strcmp(file[1], "-") == 0)
        return 0;
    return check_cd_builtin_2(file, d);
}

void cd_builtin(char **file, folder_stat *dir_stat, char **env)
{
    int dir = 0;
    if (check_cd_builtin(file, dir_stat, env) == 1)
        return;
    if (my_strcmp(file[1] , "-") == 0) {
        if (dir_stat->last_dir == NULL) {
            my_printf(": no such file or directory.\n");
            return;
        }
        dir = chdir(dir_stat->last_dir);
        cd_env(env, "PWD=", dir_stat->last_dir);
        dir_stat->last_dir = dir_stat->current_dir;
        return;
    } else {
        dir_stat->last_dir = currentfile();
        dir = chdir(file[1]);
        dir_stat->current_dir = currentfile();
        cd_env(env, "PWD=", dir_stat->current_dir);
    }
    if (dir == -1)
        my_printf("cd: not a directory: %s\n", file[1]);
}
