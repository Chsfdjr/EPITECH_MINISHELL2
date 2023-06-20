/*
** EPITECH PROJECT, 2022
** header
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <stdio.h>

typedef struct def_folder_stat {
    char *last_dir;
    char *current_dir;
} folder_stat;

int found_charc_from_buffer(const char *buffer, char charac);
int my_strlen (char const *str);
void cd_env(char **env, char *line, char *buf);
int my_strlen_charc(char const *str, char charc);
int check_arg_env(char **tab, int len_tab);
int my_strncmp(char const *s1 , char const *s2 , int n);
int my_strcmp(char const *s1 , char const *s2);
void mysh(char **av, char **env, int value, folder_stat *dir_stat);
int execute_print(char **av, char **env, int value, folder_stat *dir_stat);
int my_printf(const char *format, ...);
char *found_envline(char **env, char *line);
void cd_builtin(char **file, folder_stat *dir_stat, char **env);
void *makepartofbuffer(char *map, char *buffer, int j);
char **createmapfrombuffer(char *buffer, int y);
char **my_str_to_word_array(char *buf, char *del);
char *add_to_buffer(const char *buffer, char *adder, int flag);
char **put_in_map(char *buffer, ssize_t nb);
int count_elem(char *buffer);
int my_strcmp(char const *s1 , char const *s2);
void check_signal(void);
char *currentfile(void);
char **removeinenv(char **env, char **buffer);
void controller(int signo);
char **mod_env(char **buffer, char **env, int flag);
void printenv(char **env);
char **check_builtin(char *buf, char **env, folder_stat *dir_stat);
char **check_builtin_2(char **tab, char **env, folder_stat *dir_stat);
char **my_str_to_word_array(char *buf, char *del);
char **mod_env_2(char **env, int len_tab, char **buffer);
int check_mod_env(char **buffer);
int nb_of_char(char *str, char charc);
void error_handling(int value, char *cmd);
void exit_print(void);

#endif
