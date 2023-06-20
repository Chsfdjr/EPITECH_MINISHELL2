/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

void error_handling2(int value, char *cmd)
{
    if (WTERMSIG(value) == SIGSEGV)
        my_printf("Segmentation fault");
    if (WTERMSIG(value) == SIGABRT)
        my_printf("Floating exception");
    if (WTERMSIG(value) == SIGHUP)
        my_printf("Hangup");
    if (WTERMSIG(value) == SIGQUIT)
        my_printf("Quit");
    if (WTERMSIG(value) == SIGKILL)
        my_printf("Killed");
}

void error_handling(int value, char *cmd)
{
    if (WTERMSIG(value) == SIGBUS)
        my_printf("Bus error");
    if (WTERMSIG(value) == SIGTERM)
        my_printf("Terminated");
    if (WTERMSIG(value) == SIGALRM)
        my_printf("Alarm clock");
    if (WTERMSIG(value) == 1)
        my_printf("%s: Exec format error. Wrong Architecture.", cmd);
    error_handling2(value, cmd);
    if (WCOREDUMP(value))
        my_printf(" (core dumped)");
    my_printf("\n");
}

void exit_print(void)
{
    my_printf("exit\n");
    exit(0);
}
