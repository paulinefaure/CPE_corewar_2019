/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_put_nbr_base
*/

#include "my.h"

void my_put_nbr_base(unsigned char nb, char *base)
{
    if (nb >= my_strlen(base))
        my_put_nbr_base(nb / my_strlen(base), base);
    my_putchar(base[nb % my_strlen(base)]);
}