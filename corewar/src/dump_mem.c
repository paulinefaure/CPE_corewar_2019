/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** dump_mem
*/

#include <unistd.h>
#include "op.h"
#include "my.h"

static void print_byte(char mem)
{
    if (!(mem & 0xF0))
        write(1, "0", 1);
    my_put_nbr_base((unsigned char) mem, "0123456789ABCDEF");
}

void vm_dump_mem(char memory[])
{
    for (int i = 0; i < MEM_SIZE / 32; ++i) {
        for (int y = 0; y < 32; ++y)
            print_byte(memory[i * 32 + y]);
        write(1, "\n", 1);
    }
}