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

int enode_parse_cb(enode_node_t *root, char *filename, void *data)
{
    (void) data;
    header_t header;
    int fd = fs_open_file(replace_extension(filename, ".cor"), "w");
    if (fd == -1)
        return (84);
    my_memset(&header, 0, sizeof(header_t));
    write_exec_magic(&header);
    write_comment_header(root, &header);
    header.prog_size = (unsigned int) get_enode_size(root);
    invert_byte(&header.prog_size);
    write(fd, &header, sizeof(header_t));
    for (enode_node_t *node = root; node; node = node->next) {
        if (node->type == node_label && node->label.instruction &&
            conversion_instruction(fd, root, node->label.instruction) == 84)
            return (84);
        if (node->type == node_instruction &&
            conversion_instruction(fd, root, node) == 84)
            return (84);
    }
    return (0);
}

void enode_clean_up_cb(void *data)
{
    (void) data;
}
