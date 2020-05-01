/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int length = my_strlen(src);
    char *str = malloc(sizeof(char) * length);

    for (int i = 0; i <= length; i++)
        str[i] = src[i];
    return (str);
}