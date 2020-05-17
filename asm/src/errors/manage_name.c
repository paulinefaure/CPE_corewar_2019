/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manage_name.c
*/

#include "my.h"
#include "macros.h"
#include "errors.h"

int find_name(char **tab)
{
    int x = 0;

    for (; tab[x] != NULL; x++) {
        if (my_strncmp(tab[x], ".name", 5) == 0)
            return (x);
    }
    return (84);
}

int manage_name(char **tab)
{
    int x = find_name(tab);

    if (x == 84)
        return (EXIT_EPITECH);
    if (check_quotes_name(tab[x]) == 84)
        return (EXIT_EPITECH);
    return (0);
}