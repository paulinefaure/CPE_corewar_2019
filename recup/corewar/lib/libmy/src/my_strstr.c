/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_strncmp(str + i, to_find, my_strlen(to_find) - 1))
            return (str + i);
    return (NULL);
}