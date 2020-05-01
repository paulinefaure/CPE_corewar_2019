/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

const char *RESET = "\33[0m";
const char *RED = "\33[31m";
const char *YELLOW = "\33[33m";

void
print_n_reset_errors(context_t * context)
{
    for (int i = 0; i < context->error_stack_size; i++) {
        fsprintf(2, "%sERROR:%s%s (Line:%d): %s%s\n",
                RED, RESET, YELLOW,
                context->error_stack[i].line,
                context->error_stack[i].str, RESET);
    }
    context->error_stack_size = 0;
}
