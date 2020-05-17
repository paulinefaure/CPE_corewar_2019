/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manage_comment.c
*/

#include "my.h"
#include "macros.h"

char *delete_space(char *str)
{
    int i = 0;
    int x = 0;
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        if (str[i] == '\t' || str[i] == ' ')
            i++;
        else {
            copy[x] = str[i];
            i++;
            x++;
        }
    }
    return (copy);
}

int check_quotes_comment(char *str)
{
    int i = 8;

    str = delete_space(str);
    if (str[i] != '"')
        return (84);
    while (str[i] != '\0')
        i++;
    if (str[i - 1] != '"')
        return (84);
    return (0);
}

int check_quotes_name(char *str)
{
    int i = 5;

    str = delete_space(str);
    if (str[i] != '"')
        return (84);
    while (str[i] != '\0')
        i++;
    if (str[i - 1] != '"')
        return (84);
    return (0);
}