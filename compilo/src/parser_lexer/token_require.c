/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

bool
require_token_type(tokenizer_t * tokenizer, token_type type,
                    token_t * token_ptr)
{
    token_t token = get_token(tokenizer);

    if (token.type == type) {
        tokenizer->at = token.cur;
        tokenizer->lines += token.lines_traversed;
        if (token_ptr)
            *token_ptr = token;
        return (true);
    }
    return (false);
}

bool
token_match(token_t token, char *string)
{
    return (!my_strncmp(token.txt, string, token.length) &&
            string[token.length] == 0);
}

bool
require_token(tokenizer_t * tokenizer, char *string, token_t * token_ptr)
{
    token_t token = get_token(tokenizer);
    bool result = false;

    if (token_match(token, string)) {
        tokenizer->at = token.cur;
        tokenizer->lines += token.lines_traversed;
        if (token_ptr)
            *token_ptr = token;
        result = true;
    }
    return (result);
}
