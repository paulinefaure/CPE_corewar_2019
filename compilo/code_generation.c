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

struct header_t
{
    int header;
    int impl;
};

int
generate_code(int count, char **filenames)
{
    struct header_t files = { 0 };

    enode_node_custom_t custom = {
        .parse = &enode_parse_cb,
        .clean_up = &enode_clean_up_cb,
        .user_data = &files,
    };
    return (enode_node_parser(&custom, filenames, count));
}
