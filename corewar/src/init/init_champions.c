/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_champions
*/

#include "vm.h"

static unsigned char arrlen(char **paths)
{
    unsigned char len = 0;

    for (; paths[len]; ++len);
    return (len);
}

void vm_init_champions(char **paths, vm_t *vm)
{
    vm->nb_champs = arrlen(paths);
    for (unsigned char i = 0; i < vm->nb_champs; ++i)
        vm_init_champ(paths[i], &vm->champions[i]);
}