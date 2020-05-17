/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len = my_strlen(dest);
    char *ptr = dest + len;

    for (int i = 0; src[i] && i < n; i++)
        ptr[i] = src[i];
    return (dest);
}