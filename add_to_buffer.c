/*
** EPITECH PROJECT, 2023
** header
** File description:
** minishell
*/

#include "include/minishell.h"

char *next_part(char *new_buffer, const char *buffer, char *adder)
{
    int i = 0;
    int e = 0;

    for (i = 0 ; buffer[i] != '\0' ; i++)
        new_buffer[i] = buffer[i];
    for (e = 0 ; adder[e] != '\0' ; e++) {
        new_buffer[i] = adder[e];
        i++;
    }
    new_buffer[i] = '\0';
    return new_buffer;
}

char *add_to_buffer(const char *buffer, char *adder, int flag)
{
    int i = 0;
    int e = 0;
    int len_newbuf = 0;
    char *new_buffer = NULL;

    if (buffer == NULL || adder == NULL)
        return new_buffer;
    len_newbuf = my_strlen(buffer) + my_strlen(adder);
    new_buffer = malloc(sizeof(char) * len_newbuf + 1);
    if (flag == 1) {
        for (i = 0 ; adder[i] != '\0' ; i++)
            new_buffer[i] = adder[i];
        for (e = 0 ; buffer[e] != '\0' ; e++) {
            new_buffer[i] = buffer[e];
            i++;
        }
        new_buffer[i] = '\0';
    } else
        new_buffer = next_part(new_buffer, buffer, adder);
    return new_buffer;
}
