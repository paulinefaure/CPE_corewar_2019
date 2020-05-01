/*
** EPITECH PROJECT, 2019
** graph_write_type
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

void
write_enode_node_type_usage(int fd, enode_node_t * root, int nest)
{
    char spaces[255] = "";
    static int bracket_count = 1;
    if (root->type_usage.struct_declaration) {
        bracket_count++;
        enode_node__write_graph_c(fd, root->type_usage.struct_declaration,
                                0, nest + 1);
        bracket_count--;
    } else {
        if (bracket_count > 1) {
            my_memset(spaces, ' ', bracket_count * 4);
        } else
            my_memset(spaces, ' ', 4);
        fsprintf(fd, "%s%s ", spaces, root->string);
    }
    for (int i = 0; i < root->type_usage.ptr_count; ++i) {
        fsprintf(fd, "*");
    }
}
