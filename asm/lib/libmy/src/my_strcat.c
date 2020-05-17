/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcat
*/

#include <my.h>

char *my_strcat(char *dest, char const *src)
{
    char *ptr = dest + my_strlen(dest);

    for (int i = 0; src[i]; i++)
        ptr[i] = src[i];
    return (dest);
}