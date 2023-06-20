/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** myputnbr
*/

void my_putchar (char c);

int my_put_nbr(int nb)
{
    if ((nb / 10) == 0) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_putchar ((nb % 10) + '0');
    }
    return 0;
}
