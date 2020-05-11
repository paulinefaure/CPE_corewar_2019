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

void
enode_parse_cb(enode_node_t * root, char *filename, void *data)
{
    int fd = fs_open_file(replace_extension(filename, ".cor"), "w");
    if (fd == -1)
        return;
    for (enode_node_t *node = root; node; node = node->next) {
        if (node->type == node_label && node->label.instruction)
            conversion_instruction(fd, root, node->label.instruction);
        if (node->type == node_instruction)
            conversion_instruction(fd, root, node);
    }
}

void
enode_clean_up_cb(void *data)
{
    // struct header_t *file = data;

    // close(file->impl);
}
