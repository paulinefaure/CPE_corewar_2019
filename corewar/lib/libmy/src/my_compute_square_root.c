/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    float half = nb / 2;
    float tmp = 0;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    while (half != tmp) {
        tmp = half;
        half = (nb / tmp + tmp) / 2;
    }
    if (half != (int) half)
        return (0);
    return (half);
}