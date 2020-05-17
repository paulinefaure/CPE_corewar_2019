/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_memory
*/

#include <stdlib.h>
#include "vm.h"

void vm_init_memory(char memory[])
{
    for (int i = 0; i < MEM_SIZE; ++i)
        memory[i] = i % 256;
}