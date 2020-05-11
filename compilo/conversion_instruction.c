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
#include "op.h"

struct header_t {
    int header;
    int impl;
};

int get_opcode(char *name)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, name) == 0)
            return op_tab[i].code;
    }
}

void write_zero(int fd, size_t n)
{
    int zero = 0x00;
    for (int i = 0; i < n; i++) {
        write(fd, &zero, 1);
    }
}

void write_directive(int fd, enode_node_t *root,
                    enode_node_t *node, enode_node_t *arg)
{
    int ar = my_getnbr(arg->string + 1);
    if (arg->type == node_dir_label) {
        size_t label_pos = get_label_position(root, arg->string + 2);
        size_t label_call = get_request_label_position(root, node);
        size_t diff = label_pos - label_call;
        ar = diff;
        if (ar > 0) {
            write_zero(fd, arg->size - 1);
            write(fd, &ar, 1);
        } else {
            int val = 255;
            write(fd, &val, 1);
            write(fd, &ar, 1);
        }
    } else {
        ar = my_getnbr(arg->string + 1);
        write_zero(fd, arg->size - 1);
        write(fd, &ar, 1);
    }
}

void conversion_instruction(int fd, enode_node_t * root, enode_node_t *node)
{
    int op = get_opcode(node->string);
    write(fd, &op, sizeof(char));
    if (node->argcode)
        write(fd, ((char *)(&(node->argcode))), 1);
    for (enode_node_t *arg = node->first_arg; arg; arg = arg->next) {
        if (arg->flag & T_DIR)
            write_directive(fd, root, node, arg);
        if (arg->flag & T_REG) {
            int ar = my_getnbr(arg->string + 1);
            write_zero(fd, arg->size - 1);
            write(fd, &ar, 1);
        }
        if (arg->flag & T_IND) {
            int ar = my_getnbr(arg->string);
            write_zero(fd, arg->size - 1);
            write(fd, &ar, 1);
        }
    }
}