/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_vm
*/

#include "vm.h"

void vm_init_vm(vm_t *vm)
{
    vm_init_memory(vm->mem);
}