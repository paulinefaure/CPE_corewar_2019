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
    return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '#');
}

void next_line(char **c)
{
    while (**c && **c != '\n') {
        (*c)++;
    }
}

int
skip_whitespace(char **c)
{
    int line = 0;

    while (**c && is_whitespace(**c)) {
        if (**c == '\n' || **c == '\0')
            ++line;
        if (**c == '#') {
            next_line(c);
        } else
            (*c)++;
    }
    return (line);
}
