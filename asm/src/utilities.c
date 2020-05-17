/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

char *context_strcat_dup(context_t * cont, char *str1, char *str2)
{
    if (!str1)
        return (str2);
    if (!str2)
        return (str1);
    int len = (my_strlen(str1) + my_strlen(str2) + 1);
    char *new = context_allocate_memory(cont, sizeof(char) * (len));

    if (new) {
        my_strncpy(new, str1, my_strlen(str1));
        my_strncat(new, str2, my_strlen(str2));
        return (new);
    }
    return (NULL);
}

char *context_strdup(context_t * cont, char *src)
{
    int len = my_strlen(src) + 1;
    char *str = context_allocate_memory(cont, sizeof(char) * (len));

    my_strcpy(str, src);
    return (str);
}

int my_char_is_symbol(int c)
{
    return (c == '%' || c == ':' ||
            c == ',' || c == '.');
}
