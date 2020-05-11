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

enode_node_t *new_header_node(context_t *ctx, token_t *name, token_t *token)
{
    enode_node_t *new = 0;
    new = context_allocate_node(ctx);
    new->string = name->txt;
    new->length = name->length;
    new->header.value = context_allocate_node(ctx);
    new->header.value->string = token->txt;
    new->header.value->length = token->length;
    new->type = node_header;
    return (new);
}

void parse_header(context_t *ctx, tokenizer_t *tokenizer, enode_node_t **new)
{
    token_t name = {0};
    token_t token = {0};

    if (require_token(tokenizer, "name", &name)) {
        if (!require_token_type(tokenizer, token_string, &token))
            context_push_error(ctx, tokenizer, "Expected .name value");
        *new = new_header_node(ctx, &name, &token);
    }
    if (require_token(tokenizer, "comment", &name)) {
        if (!require_token_type(tokenizer, token_string, &token))
            context_push_error(ctx, tokenizer, "Expected .comment value");
        *new = new_header_node(ctx, &name, &token);
    }
}

static enode_node_t *
parse__code(context_t *ctx, tokenizer_t *tokenizer, token_t *name)
{
    enode_node_t *new = 0;
    token_t token = {0};

    if (require_token_type(tokenizer, token_label, name)) {
        new = context_allocate_node(ctx);
        new->string = name->txt;
        new->length = name->length;
        new->type = node_label;
        if (name->txt[name->length + 1] != '\n') {
            require_token_type(tokenizer, token_alpha_num, name);
            new->label.instruction = parse_instruction(ctx, tokenizer, name);
        }
    } else if (require_token_type(tokenizer, token_alpha_num, name)) {
        new = parse_instruction(ctx, tokenizer, name);
    }
    if (require_token(tokenizer, ".", 0)) {
        parse_header(ctx, tokenizer, &new);
    }
    return (new);
}

enode_node_t *
parse_code(context_t *context, tokenizer_t *tokenizer)
{
    bool parsing = true;
    enode_node_t *root = 0, **node_store_target = &root;

    while (parsing) {
        token_t token = peek_token(tokenizer), name = { 0 };
        enode_node_t *new_node = 0;
        IF_THEN(token.type == token_eof, break);
        new_node = parse__code(context, tokenizer, &name);
        if (new_node != 0) {
            *node_store_target = new_node;
            node_store_target = &(*node_store_target)->next;
        } else
            break;
    }
    return (root);
}
