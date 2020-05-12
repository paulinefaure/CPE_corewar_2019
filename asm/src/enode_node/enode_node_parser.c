/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

struct parsed
{
    enode_node_t *root;
    char *filename;
};

char *readfile_into_mem(context_t * cont, char *filepath)
{
    int fd = fs_open_file(filepath, "r");
    char *res = NULL;

    if (fd != -1) {
        if (!verif_ext(filepath))
            return (0);
        lseek(fd, 0, SEEK_END);
        size_t size = lseek(fd, 0, SEEK_CUR);
        lseek(fd, 0, SEEK_SET);
        res = context_allocate_memory(cont, sizeof(char) * (size + 1));
        read(fd, res, size);
        res[size] = 0;
        close(fd);
    }
    return (res);
}

static void process_parsed_graph(char *filename, enode_node_t * root,
                        context_t * context, enode_node_custom_t * custom)
{
    generated_graph_str(context, root);
    if (context->exit == 0) {
        if (custom->parse &&
            custom->parse(root, filename, custom->user_data) == 84) {
            context->exit = 84;
            return;
        }
    }
    print_n_reset_errors(context);
}

static enode_node_t *parse_file(context_t *context, char *file)
{
    tokenizer_t tokenizer = { 0 };
    tokenizer.at = file;
    tokenizer.lines = 1;
    enode_node_t *root = parse_code(context, &tokenizer);
    if (context->error_stack_size > 0)
        context->exit = 84;
    print_n_reset_errors(context);
    return root;
}

int enode_node_parser(enode_node_custom_t * ctm, char **fnames, int fcount)
{
    context_t ctx = { 0 };
    int nbr_parsed = 0;
    struct parsed *parsed = context_allocate_memory(&ctx, sizeof(*parsed) *
                                                    fcount);
    ASSERT(parsed != 0);
    for (int i = 1; i < fcount; i++) {
        IF_THEN(fnames[i] == 0, continue);
        my_printf("Processing file at \"%s\".\n", fnames[i]);
        char *file = readfile_into_mem(&ctx, fnames[i]);
        LOG_ERROR(!file, continue, "Could not load '%s'.\n", fnames[i]);
        parsed[nbr_parsed].root = parse_file(&ctx, file);
        parsed[nbr_parsed].filename = fnames[i];
        ++nbr_parsed;
    }
    for (int i = 0; i < nbr_parsed; i++)
        process_parsed_graph(parsed[i].filename, parsed[i].root, &ctx, ctm);
    IF_THEN(ctm->clean_up, ctm->clean_up(ctm->user_data));
    context_clean_up(&ctx);
    return (ctx.exit);
}
