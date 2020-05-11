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

enode_node_t *
parse_args_list(context_t *ctx, tokenizer_t *tokenizer, token_t *name, int i)
{
    token_t token = {0};
    enode_node_t *root = 0, **target = &root;

    for (int j = 0; j < op_tab[i].nbr_args; j++) {
        enode_node_t *arg = parse_args(ctx, tokenizer,
                                        op_tab[i], op_tab[i].type[j]);
        if (arg == 0)
            return (0);
        require_token(tokenizer, ",", 0);
        // if (j < op_tab[i].nbr_args - 1 && !require_token(tokenizer, ",", 0))
        //     context_push_error(ctx, tokenizer, "Expected ','.");
        *target = arg;
        target = &(*target)->next;
    }
    return (root);
}

void check_use_coding_byte(op_t op, enode_node_t *new, enode_node_t *arg)
{
    if (op.use_coding_byte) {
        new->argcode = new->argcode << 2;
        if (arg->flag == T_DIR)
            new->argcode = new->argcode | 2;
        if (arg->flag == T_REG)
            new->argcode = new->argcode | 1;
        if (arg->flag == T_IND)
            new->argcode = new->argcode | 3;
    }
}

void set_total_size(op_t op, enode_node_t *new)
{
    if (new) {
        int size = 0, have_reg = 0;
        for (enode_node_t *arg = new->first_arg; arg; arg = arg->next) {
            size += arg->size;
            have_reg |= arg->size == 1;
            check_use_coding_byte(op, new, arg);
        }
        for (int i = op.nbr_args; i < 4; i++)
            new->argcode = new->argcode << 2;
        new->size = (new->argcode) ? size + 2 : size + 1;
    }
}

enode_node_t *
parse_instruction(context_t *ctx, tokenizer_t *tokenizer, token_t *name)
{
    enode_node_t *new = 0;
    op_t op;
    bool res = false;

    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strncmp(op_tab[i].mnemonique, name->txt, name->length)) {
            op = op_tab[i];
            new = context_allocate_node(ctx);
            new->string = name->txt;
            new->length = name->length;
            new->type = node_instruction;
            new->first_arg = parse_args_list(ctx, tokenizer, name, i);
            new = new->first_arg != 0 ? new : 0;
            res = true;
            break;
        }
    }
    if (res == false)
        context_push_error(ctx, tokenizer, "Invalid instruction.");
    set_total_size(op, new);
    return (new);
}