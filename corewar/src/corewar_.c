/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar_
*/

#include <stdlib.h>
#include "prototype.h"
#include "vm.h"

int corewar_(int ac, char *av[])
{
    vm_t vm;

    vm_init_vm(&vm);
    vm_dump_mem(vm.mem);
    (void)ac;
    (void)av;
    return (EXIT_SUCCESS);
}