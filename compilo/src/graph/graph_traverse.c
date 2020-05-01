/*
** EPITECH PROJECT, 2019
** generated_graph_str
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

static void
check(context_t * cont, enode_node_t * root)
{
    if (root->string) {
        char *new_string = context_allocate_memory(cont,
                                                    sizeof(char) *
                                                    (root->length + 1));
        my_memset(new_string, 0, root->length + 1);
        my_strncpy(new_string, root->string, root->length);
        root->string = new_string;
    }
}

void
generated_graph_str(context_t * cont, enode_node_t * root)
{
    if (root) {
        check(cont, root);
        generated_graph_str(cont, root->first_arg);
        if (root->type == node_label)
            generated_graph_str(cont, root->label.instruction);
        IF_THEN(root->next, generated_graph_str(cont, root->next));
    }
}
