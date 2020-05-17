/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"
#include "smart_ptr.h"

const char *extens = ".s";

bool verif_ext(char *name)
{
    char *find = my_strchr(name, '.');
    size_t len = find - name;
    char *new = malloc(sizeof(char) * (len + 1));
    bool res = false;

    my_memset(new, 0, len + 1);
    if (new) {
        my_strncpy(new, name, len);
        new = my_strcat_dup(new, my_strdup(extens));
    }
    if (!my_strcmp(name, new))
        res = true;
    else
        LOG_ERROR(1,, "'%s' is not a allow (only allow *%s)\n", name, extens);
    free(new);
    return (res);
}

char *replace_extension(char *name, char *ext)
{
    char *find = my_strchr(name, '.');
    size_t len = find - name;
    char *new = malloc(sizeof(char) * (len + 1));

    my_memset(new, 0, len + 1);
    if (new) {
        my_strncpy(new, name, len);
        new = my_strcat_dup(new, my_strdup(ext));
    }
    return (new);
}
