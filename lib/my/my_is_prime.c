/*
** EPITECH PROJECT, 2022
** prime
** File description:
** prime
*/

int my_is_prime(int nb)
{
    int coef = 1;
    int testing = 0;

    if (nb == 0 || nb == 1)
        return 0;
    while (coef <= nb) {
        if (nb % coef == 0) {
            testing ++;
            coef++;
        } else
            coef++;
    }
    if (testing > 2) {
        return 0;
    }
    if (testing == 2)
        return 1;
}
