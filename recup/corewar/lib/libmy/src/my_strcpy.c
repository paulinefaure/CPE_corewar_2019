/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpy
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return (NULL);
    for (i = 0; src[i]; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}