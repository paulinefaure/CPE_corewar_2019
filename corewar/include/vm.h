/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** vm
*/

#ifndef VM_H_
#define VM_H_

#include "op.h"

typedef struct vm_s {
    char mem[MEM_SIZE];
} vm_t;

void vm_init_memory(char memory[]);
void vm_init_vm(vm_t *vm);
void vm_dump_mem(char memory[]);

#endif /* !VM_H_ */
