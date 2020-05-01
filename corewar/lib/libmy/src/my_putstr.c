/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_putstr
*/

#include <my.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}