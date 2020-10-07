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
<<<<<<< HEAD
        break;
=======
>>>>>>> e06ac52b8155130c9d0cfcb183a27484ec98ecc1
    }
    return (EXIT_FAILURE);
}