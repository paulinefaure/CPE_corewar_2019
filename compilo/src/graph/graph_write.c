/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"


void
enode__node__write__graph__c(int fd, enode_node_t * root,
                            int follow_next, int nest)
{
    if (!root)
        return;
    if (root->type == node_type_usage)
        write_enode_node_type_usage(fd, root, nest);
}

void
enode_node__write_graph_c(int fd, enode_node_t * root,
                        int follow_next, int nest)
{
    if (root->type == node_identifier || root->type == node_string ||
        root->type == node_number || root->type == node_char)
        fsprintf(fd, "%s", root->string);
    enode__node__write__graph__c(fd, root, follow_next, nest);
    if (root->next && follow_next)
        enode_node__write_graph_c(fd, root->next, follow_next, nest);
}

void
generate_header(int fd, char *fdname)
{
    fsprintf(fd, "/*\n** EPITECH PROJECT, 2019\n");
    fsprintf(fd, "** %s\n", fdname);
    fsprintf(fd, "** File description:\n** %s\n*/\n\n", fdname);
}

void
enode_node_write_graph_c(int fd, enode_node_t * root, int follow_next)
{
    enode_node__write_graph_c(fd, root, follow_next, 0);
}
