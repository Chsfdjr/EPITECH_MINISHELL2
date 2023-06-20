/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

char **fill_bufenv(char **buffer, int check)
{
    buffer[1] = add_to_buffer(buffer[1],"=", 2);
    if (check == 2)
        buffer[1] = add_to_buffer(buffer[1], buffer[2], 2);
    return buffer;
}

char **define_buffer(char **buffer, int len_buf)
{
    char **buf = NULL;
    int i = 0;
    int check = check_arg_env(buffer, len_buf);

    if (check == 1) {
        if (nb_of_char(buffer[1], '=') > 1) {
            my_printf
            ("setenv: Variable name must contain alphanumeric characters.\n");
            return NULL;
        }
        buffer[1] = add_to_buffer(buffer[1],"setenv=", 1);
        buf = my_str_to_word_array(buffer[1], "=");
        buf[1] = add_to_buffer(buf[1],"=", 2);
        for (; buf[i] != NULL ; i++);
        if (i == 3)
            buf[1] = add_to_buffer(buf[1], buf[2], 2);
        return buf;
    }
    return fill_bufenv(buffer, check);
}

int check_exist_env(char **env, char *buffer)
{
    int len_tab = 0;
    int first_len = my_strlen_charc(buffer, '=') + 1;

    for (len_tab = 0 ; env[len_tab] != NULL ; len_tab++) {
        if (my_strncmp(env[len_tab], buffer, first_len) == 0) {
            env[len_tab] = malloc(sizeof(char) * my_strlen(buffer) + 1);
            env[len_tab] = buffer;
            return -1;
        }
    }
    return len_tab;
}

char **mod_env(char **buffer, char **env, int flag)
{
    int len_buf = check_mod_env(buffer);
    int len_tab = 0;

    if (len_buf == 84)
        return env;
    buffer = define_buffer(buffer, len_buf);
    if (buffer == NULL)
        return env;
    len_tab = check_exist_env(env, buffer[1]);
    if (len_tab == -1)
        return env;
    env = mod_env_2(env, len_tab, buffer);
    return env;
}

void printenv(char **env)
{
    for (int i = 0 ; env[i] != NULL ; i++)
        my_printf("%s\n", env[i]);
}
