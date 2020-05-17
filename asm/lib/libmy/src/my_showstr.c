/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_showstr
*/

#include <unistd.h>
#include "my.h"

static void print_non_printable(char a)
{
    my_putchar('\\');
    my_put_nbr_base((int) a, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32)
            print_non_printable(str[i]);
        else
            write(1, str + i, 1);
    }
    return (0);
}