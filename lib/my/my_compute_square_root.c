/*
** EPITECH PROJECT, 2022
** square root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int square = 0;
    int result;
    while (result != nb) {
        result = square * square;
        square++;
        if (result > nb) {
            return 0;
        }
    }
    return (square - 1);
}
