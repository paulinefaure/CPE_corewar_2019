/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** file_manager
*/

#include <stdlib.h>
#include "file.h"

int file_manager(char *file)
{
    if (file_extension(file))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}