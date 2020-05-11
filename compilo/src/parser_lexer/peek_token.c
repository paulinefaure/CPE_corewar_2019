/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

token_t
peek_token(tokenizer_t *tokenizer)
{
    token_t token = get_token(tokenizer);
    return token;
}

token_t
next_token(tokenizer_t *tokenizer)
{
    token_t token = get_token(tokenizer);
    tokenizer->at = token.cur;
    tokenizer->lines += token.lines_traversed;
    return token;
}