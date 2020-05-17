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
    char *find = 0;
    for (int i = 0; file[i]; i++)
        if (file[i] == '.')
            find = file + i;
    if (!find)
        return (EXIT_SUCCESS);
    size_t len = find - file;
    char *new = malloc(sizeof(char) * (len + 1));
    int res = EXIT_FAILURE;

    if (new) {
        my_memset(new, 0, len + 1);
        my_strncpy(new, file, len);
        new = my_strcat_dup(new, my_strdup(".s"));
        if (!my_strcmp(file, new))
            res = EXIT_SUCCESS;
    }
    free(new);
    return (res);
}