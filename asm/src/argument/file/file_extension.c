/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** file_extension
*/

#include <stdlib.h>
#include "my.h"

int file_extension(char *file)
{
    char *extension = my_strstr(file, ".s");

    switch (my_strcmp(extension, ".s"))
    {
    case 0:
        return (EXIT_SUCCESS);
        break;
    }
    return (EXIT_FAILURE);
}