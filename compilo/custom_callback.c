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

struct header_t {
    int header;
    int impl;
};

void
enode_init_cb(void *data)
{

}

void
enode_parse_cb(enode_node_t * root, char *filename, void *data)
{
    for (enode_node_t *node = root; node; node = node->next) {
        if (node->first_arg) {
            my_printf("Size: %d\n", node->size);
        }
        if (node->type == node_label && node->label.instruction) {
            my_printf("Size: %d\n", node->label.instruction->size);
        }
        my_printf("%d: %s\n\n", node->type, node->string);
    }
}

void
enode_clean_up_cb(void *data)
{
    // struct header_t *file = data;

    // close(file->impl);
}
