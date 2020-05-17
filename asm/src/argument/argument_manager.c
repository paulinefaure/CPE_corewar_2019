/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** argument_manager
*/

#include <stdlib.h>
#include "file.h"
#include "macros.h"
#include "my.h"

int argument_manager(int ac, char *av[])
{
    switch (ac)
    {
    case 2:
        if (my_strcmp(av[1], "-h") == 0)
            return (EXIT_HELP);
        else
            if (file_manager(av[1]) == 0)
                return (EXIT_SUCCESS);
        break;
    default:
        break;
    }
    return (EXIT_FAILURE);
}