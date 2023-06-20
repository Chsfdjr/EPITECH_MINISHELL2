/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

int found_charc_from_buffer(const char *buffer, char charac)
{
    int i = 0;

    for (i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] == charac)
            return 0;
    }
    return -1;
}
