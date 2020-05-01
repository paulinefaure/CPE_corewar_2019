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

static char *
get_binary_op_str_from_type(int type)
{
    static char *binary_operator_strings[] = {
        "INVALIDBINARYOPERATOR",
        "+", "-", "*", "/", "%",
        "<<", ">>",
        "&", "|", "&&", "||",
    };

    return binary_operator_strings[type];
}

int
get_binary_op_type_from_token(token_t token)
{
    int type = enode_binary_op_type_invalid;

    for (int i = 1; i < enode_binary_op_type_max; ++i) {
        if (token_match(token, get_binary_op_str_from_type(i))) {
            type = i;
            break;
        }
    }
    return type;
}
