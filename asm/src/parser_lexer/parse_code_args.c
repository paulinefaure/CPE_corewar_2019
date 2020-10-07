/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"
#include "op.h"

void set_node(enode_node_t *new, token_t *token, int size, int flag)
{
    new->string = token->txt;
    new->length = token->length;
    new->size = size;
    new->flag |= flag;
}

void parse_args_dir(context_t *ctx, tokenizer_t *toke,
                            op_t op, enode_node_t *new)
{
    token_t token;
    if (require_token_type(toke, token_dir_label, &token)) {
        set_node(new, &token, op.use_index ? IND_SIZE : DIR_SIZE, T_DIR);
        new->type = node_dir_label;
    } else if (require_token_type(toke, token_dir_number, &token)) {
        set_node(new, &token, op.use_index ? IND_SIZE : DIR_SIZE, T_DIR);
    } else {
        context_push_error(ctx, toke, "Error Occured\n");
        new = 0;
    }
}

enode_node_t *parse_args(context_t *ctx, tokenizer_t *toke,
                                    op_t op, args_type_t type)
{
    token_t token = {0};
    enode_node_t *new = context_allocate_node(ctx);

    if ((type & T_REG) && require_token_type(toke, token_register, &token)) {
        set_node(new, &token, 1, T_REG);
    } else if ((type & T_DIR)) {
        parse_args_dir(ctx, toke, op, new);
    } else {
        if ((type & T_IND) && require_token_type(toke, token_number, &token))
            set_node(new, &token, IND_SIZE, T_IND);
        else {
            context_push_error(ctx, toke, "Expected arg type\n");
            new = 0;
        }
    }
    return (new);
}