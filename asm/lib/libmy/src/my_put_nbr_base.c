/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_put_nbr_base
*/

#include "my.h"

void my_put_nbr_base(int nb, char *base)
{
    nb = (nb < 0) ? my_putchar('-'), -nb : nb;
    if (nb >= my_strlen(base))
        my_put_nbr_base(nb / my_strlen(base), base);
    my_putchar(base[nb % my_strlen(base)]);
}