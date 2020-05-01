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
parse_args(context_t *ctx, tokenizer_t *tokenizer, op_t op, args_type_t type)
{
    token_t token = {0};
    enode_node_t *new = context_allocate_node(ctx);

    if ((type & T_REG) &&
        require_token_type(tokenizer, token_register, &token)) {
        my_printf("Instruction Register\n");
        new->string = token.txt;
        new->length = token.length;
        new->size = 1;
        new->flag = T_REG;
    } else if ((type & T_DIR)) {
        new->size = op.use_index ? IND_SIZE : DIR_SIZE;
        new->flag |= T_DIR;
        if (require_token_type(tokenizer, token_dir_label, &token)) {
            my_printf("Instruction Dir Label\n");
            new->string = token.txt;
            new->length = token.length;
        } else if (require_token_type(tokenizer, token_dir_number, &token)) {
            my_printf("Instruction Dir\n");
            new->string = token.txt;
            new->length = token.length;
        } else
            my_printf("Error Occured\n");
    } else if ((type & T_IND) &&
        require_token_type(tokenizer, token_number, &token)) {
        my_printf("Instruction Ind\n");
        new->string = token.txt;
        new->length = token.length;
        new->size = IND_SIZE;
        new->flag = T_IND;
    } else {
        my_printf("Instruction Error\n");
        context_push_error(ctx, tokenizer, "Expected arg type\n");
    }
    if (!require_token(tokenizer, ",", 0)) {
        if (peek_token(tokenizer).type != token_alpha_num &&
            peek_token(tokenizer).type != token_label &&
            peek_token(tokenizer).type != token_eof)
            context_push_error(ctx, tokenizer, "Expected ', '\n");
    }
    return (new);
}

enode_node_t *
parse_args_list(context_t *ctx, tokenizer_t *tokenizer, token_t *name, int i)
{
    token_t token = {0};
    enode_node_t *root = 0, **target = &root;

    for (int j = 0; j < op_tab[i].nbr_args; j++) {
        enode_node_t *arg = parse_args(ctx, tokenizer,
                                        op_tab[i], op_tab[i].type[j]);
        *target = arg;
        target = &(*target)->next;
    }
    return (root);
}

enode_node_t *
parse_instruction(context_t *ctx, tokenizer_t *tokenizer, token_t *name)
{
    enode_node_t *new = 0;
    token_t token;
    op_t op;

    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strncmp(op_tab[i].mnemonique, name->txt, name->length)) {
            op = op_tab[i];
            new = context_allocate_node(ctx);
            new->string = name->txt;
            new->length = name->length;
            new->type = node_instruction;
            new->first_arg = parse_args_list(ctx, tokenizer, name, i);
        }
    }
    if (new) {
        int size = 0, have_reg = 0;
        for (enode_node_t *arg = new->first_arg; arg; arg = arg->next) {
            size += arg->size;
            have_reg |= arg->size == 1;
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
        for (int i = 0; i < 4; i++)
            new->argcode = new->argcode << 2;
        printf("ArgCode: %d\n", new->argcode);
        new->size = have_reg ? size + 2 : size + 1;
    }
    return (new);
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
            printf("Instr\n", new->label.instruction->length, new->label.instruction->string);
        }
    } else if (require_token_type(tokenizer, token_alpha_num, name)) {
        printf("Instruction\n");
        new = parse_instruction(ctx, tokenizer, name);
    }
    if (require_token(tokenizer, ".", 0)) {
        if (require_token(tokenizer, "name", name)) {
            if (!require_token_type(tokenizer, token_string, &token))
                context_push_error(ctx, tokenizer, "Expected .name value");
            new = context_allocate_node(ctx);
            new->string = name->txt;
            new->length = name->length;
            new->header.value = context_allocate_node(ctx);
            new->header.value->string = token.txt;
            new->header.value->length = token.length;
            new->type = node_header;
        }
        if (require_token(tokenizer, "comment", name)) {
            if (!require_token_type(tokenizer, token_string, &token))
                context_push_error(ctx, tokenizer, "Expected .comment value");
            new = context_allocate_node(ctx);
            new->string = name->txt;
            new->length = name->length;
            new->header.value = context_allocate_node(ctx);
            new->header.value->string = token.txt;
            new->header.value->length = token.length;
            new->type = node_header;
        }
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
