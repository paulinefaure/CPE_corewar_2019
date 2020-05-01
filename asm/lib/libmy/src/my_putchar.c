/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}