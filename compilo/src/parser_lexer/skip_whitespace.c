/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** skip whitespace
*/

#include "my.h"
#include "parser.h"

int lines = 1;

static bool
is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t' || c == '\r');
}

int
skip_whitespace(char **c)
{
    int space = 0;
    int line = 0;

    while (**c && is_whitespace(**c)) {
        if (**c == '\n' || **c == '\0')
            ++line;
        (*c)++;
        space++;
    }
    while (**c == '#') {
        char *end = my_strchr(*c, '\n');
        if (end) {
            line++;
            *c = end + 1;
        }
    }
    return (line);
}
