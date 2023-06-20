/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

char *currentfile(void)
{
    int size = 1000;
    char *buffer = malloc(sizeof(char) * size);
    buffer = getcwd(buffer, size);
    return buffer;
}

void execute_binary(char **bin_exec, char **av, char **env)
{
    int i = 0;

    bin_exec[i] = add_to_buffer(bin_exec[i], "/", 2);
    while (bin_exec[i] != NULL) {
        bin_exec[i] = add_to_buffer(bin_exec[i], av[0], 2);
        if (access(bin_exec[i], X_OK) == 0) {
            execve(bin_exec[i], av, env);
            return;
        }
        i++;
        bin_exec[i] = add_to_buffer(bin_exec[i],"/", 2);
    }
    my_printf("%s: Command not found.\n", av[0]);
}

int execute_print(char **av, char **env, int value, folder_stat *dir_stat)
{
    char **bin_exec = my_str_to_word_array(found_envline(env, "PATH="), ":");
    pid_t pid = getpid();
    pid_t child = fork();

    if (bin_exec == NULL)
        return 0;
    bin_exec[0] = add_to_buffer(bin_exec[0], "/", 2);
    if (child > 0) {
        waitpid(child, &value, 0);
        error_handling(value, av[0]);
        return 0;
    }
    if (child == 0) {
        if (access(av[0], X_OK) == 0) {
            execve(av[0], av, env);
            return 0;
        } else
            execute_binary(bin_exec, av, env);
    }
    return 0;
}

void mysh(char **av, char **env, int value, folder_stat *dir_stat)
{
    char **tab = NULL;
    size_t size = 0;
    int rd = 0;
    int len_tab = 0;
    int i = 0;
    char *buf = "\0";
    while (value != -99999) {
        my_printf("$ %s> ", dir_stat->current_dir);
        check_signal();
        rd = getline(&buf, &size, stdin);
        if (rd == -1)
            exit_print();
        if (rd == 1)
            continue;
        tab = my_str_to_word_array(buf, ";");
        while (tab[len_tab] != NULL)
            len_tab++;
        if (len_tab == 0)
            continue;
        for (i = 0 ; i < len_tab ; i++)
            env = check_builtin(tab[i], env, dir_stat);
    }
}

int main(int ac, char **av, char **env)
{
    int value = 0;
    folder_stat *dir_stat = malloc(sizeof(folder_stat));
    dir_stat->current_dir = currentfile();
    dir_stat->last_dir = NULL;

    if (ac > 1) {
        write(2, "input error", 12);
        return 84;
    } else
        mysh(av, env, value, dir_stat);
    return 0;
}
