/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manage_errors.c
*/

#include "macros.h"
#include "errors.h"
#include <stdio.h>

int manage_errors(char *str)
{
    char **tab = manage_file(str);
    printf("toto");
    if (manage_name(tab) == 84)
        return (EXIT_EPITECH);
    if (manage_comment(tab) == 84)
        return (EXIT_EPITECH);
    return (0);
}