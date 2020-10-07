/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

void invert_byte(int *val)
{
    int i = 3;
    unsigned int revnbr;
    unsigned int nbr = *val;

    while (i >= 0) {
        ((char *)(&revnbr))[i] = ((char *)(&nbr))[0];
        nbr = nbr >> 8;
        i--;
    }
    *val = revnbr;
}

void write_exec_magic(header_t *header)
{
    header->magic = COREWAR_EXEC_MAGIC;
    invert_byte(&(header->magic));
}

void write_comment_header(enode_node_t *root, header_t *header)
{
    for (enode_node_t *node = root; node; node = node->next) {
        if (node->type == node_header &&
            !my_strncmp(node->string, "name", node->length))
            my_strncpy(header->prog_name, node->header.value->string,
                                        node->header.value->length);
        if (node->type == node_header &&
            !my_strncmp(node->string, "comment", node->length))
            my_strncpy(header->comment, node->header.value->string,
                                        node->header.value->length);
    }
}

size_t get_enode_size(enode_node_t *current)
{
    size_t size = 0;

    while (current) {
        if (current->type == node_label && current->label.instruction)
            size += current->label.instruction->size;
        else
            size += current->size;
        current = current->next;
    }
    return (size);
}