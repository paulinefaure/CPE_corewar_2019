/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

void parse_string(char **c, token_t *token)
{
    token->txt = *c;
    char *end = my_strchr(*c, '"');
    if (!end)
        return;
    token->type = token_string;
    token->length = end - token->txt;
    *c = end + 1;
}

void parse_alpha(char **c, token_t *token)
{
    token->type = token_alpha_num;
    while (my_char_isalpha(**c) || my_char_isnum(**c) || **c == '_') {
        ++(*c);
    }
    token->length = *(c) - token->txt;
    if (token->length == 2 && token->txt[0] == 'r' &&
        my_char_isnum(token->txt[1]))
        token->type = token_register;
    if (**(c) == ':') {
        token->type = token_label;
        (*c)++;
    }
}

void parse_number(char **c, token_t * token)
{
    token->type = token_number;
    while (my_char_isnum(**c))
        ++(*c);
    token->length = *c - token->txt;
}
