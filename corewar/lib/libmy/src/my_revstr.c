/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_revstr
*/

#include <my.h>

static void swap_char(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int z = my_strlen(str) - 1;
    int i;

    for (i = 0; i < z - i; i++)
        swap_char(str + i, str + z - i);
    return (str);
}