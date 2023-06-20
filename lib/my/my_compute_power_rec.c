/*
** EPITECH PROJECT, 2022
** power rev
** File description:
** task04
*/

#include <stdio.h>

int my_compute_power_rec (int nb, int p)
{
    int newnb = nb;

    if (p == 0) {
        return 1;
        }
    if (p > 0) {
        return (newnb * (my_compute_power_rec(nb,p - 1)));
    } else {
        return 0;
    }
}
