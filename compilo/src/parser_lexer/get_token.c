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
parse_other(char t, char **c, token_t *token)
{
    if (my_char_isalpha(t)) {
        parse_alpha(c, token);
    } else if (my_char_isnum(t)) {
        parse_number(c, token);
    } else {
        token->type = token_unknown;
    }
}

void token_dir(char **c, token_t *token)
{
    if (my_char_isnum(**c)) {
        token->type = token_dir_number;
        while (my_char_isnum(**c))
            ++(*c);
        token->length = *c - token->txt;
    } else if (**c == ':') {
        token->type = token_dir_label;
        ++(*c);
        while (my_char_isalpha(**c) || my_char_isnum(**c) || **c == '_')
            ++(*c);
        token->length = (*c) - token->txt;
    }
}

token_t
get_token(tokenizer_t *tokenizer)
{
    char *c = tokenizer->at;
    int line = skip_whitespace(&c);
    token_t token = {.length = 1, .txt = c, 0 };
    char t = *c;

    ++c;
    ASSIGN_RETURN_IF(t == '\0', token.type = token_eof, return (token));
    if (t == '%') {
        token_dir(&c, &token);
        token.lines_traversed = line;
        token.cur = c;
        return (token);
    } else if (t == '"') {
        parse_string(&c, &token);
    } else
        parse_other(t, &c, &token);
    token.lines_traversed = line;
    token.cur = c;
    return (token);
}
