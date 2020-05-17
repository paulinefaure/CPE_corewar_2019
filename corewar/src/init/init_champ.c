/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_champ
*/

#include "stdlib.h"
#include "my.h"
#include "vm.h"

// The 4 is here to trim the .cor file extension
static void set_name(char *dest, char *path)
{
    char *tmp = NULL;

    tmp = malloc(sizeof(char) * my_strlen(path));
    if (!tmp)
        return;
    for (int i = 0; i < my_strlen(path); ++i)
        tmp[i] = 0;
    my_strcpy(tmp, path);
    my_revstr(tmp);
    for (int i = 4; tmp[i] && tmp[i] != '/'; ++i)
        dest[i - 4] = tmp[i];
    my_revstr(dest);
    free(tmp);
}

void vm_init_champ(char *path, champ_t *champion)
{
    champion->cursor = 0;
    champion->last_live_cycle = 0;
    for (int i = 0; i < 256; ++i)
        champion->name[i] = 0;
    set_name(champion->name, path);
}