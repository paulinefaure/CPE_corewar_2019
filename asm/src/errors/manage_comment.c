/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manage_errors.c
*/

#include <stdio.h>
#include "errors.h"
#include "macros.h"
#include "my.h"

int find_comment(char **tab)
{
    int x = 0;

    for (; tab[x] != NULL; x++) {
        if (my_strncmp(tab[x], ".comment", 7) == 0)
            return (x);
    }
    return (84);
}
    int i = 0;

int manage_comment(char **tab)
{
    int x = find_comment(tab);

    if (x == 84)
        return (EXIT_EPITECH);
    if (check_quotes_comment(tab[x]) == 84)
        return (EXIT_EPITECH);
    return (0);
}