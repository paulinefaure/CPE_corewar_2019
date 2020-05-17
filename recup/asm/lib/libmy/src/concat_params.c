/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** concat_params
*/

#include <my.h>
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int length = 0;

    for (int i = 0; i < argc; i++)
        length += my_strlen(argv[i]) + 1;
    char *str = malloc(sizeof(char) * (length + 1));
    char *str_old = str;
    for (int i = 0; i < argc; i++, str++) {
        for (int z = 0; argv[i][z]; z++, str++)
            *str = argv[i][z];
        *str = '\n';
    }
    *str = '\0';
    return (str_old);
}