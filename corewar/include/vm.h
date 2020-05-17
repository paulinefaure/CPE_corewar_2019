/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** vm
*/

#ifndef VM_H_
#define VM_H_

#include <stdlib.h>
#include "op.h"

typedef struct champ_s {
    int cursor;
    size_t last_live_cycle;
    char name[256];
} champ_t;

typedef struct vm_s {
    char mem[MEM_SIZE];
    size_t nb_cycle;
    unsigned char nb_champs;
    champ_t champions[4];
} vm_t;

void vm_init_memory(char memory[]);
void vm_init_vm(vm_t *vm);
void vm_dump_mem(char memory[]);
void vm_init_champ(char *path, champ_t *champion);

#endif /* !VM_H_ */
