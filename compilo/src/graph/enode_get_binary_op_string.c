/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

char *
enode_get_binary_op_string(int type)
{
    char *strings[] = {
        "(invalid)",
        "+",
        "-",
        "*",
        "/",
        "%",
        "<<",
        ">>",
        "&",
        "|",
        "&&",
        "||",
    };
    return strings[type];
}

char *
enode_get_unary_op_string(int type)
{
    char *strings[] = {
        "(invalid)",
        "-",
        "!",
        "~",
    };
    return strings[type];
}
