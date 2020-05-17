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

size_t get_label_position(enode_node_t *first, char *labelname)
{
    enode_node_t *current = first;
    int count = 0;
    bool finded = false;

    while (current) {
        if (!my_strcmp(current->string, labelname) && current->type == node_label) {
            finded = true;
            break ;
        }
        count += current->size;
        current = current->next;
    }
    if (!finded) {
        my_printf("Label not exist\n");
        exit(84);
    }
    return (count);
}

size_t get_request_label_position(
    enode_node_t *first, enode_node_t *tofind)
{
    enode_node_t *current = first;
    int count = 0;
    bool finded = false;

    while (current) {
        if (current == tofind) {
            finded = true;
            break ;
        }
        if (current->type == node_label && current->label.instruction)
            count += current->label.instruction->size;
        count += current->size;
        current = current->next;
    }
    if (!finded) {
        my_printf("Unknow error\n");
        exit(84);
    }
    return (count);
}