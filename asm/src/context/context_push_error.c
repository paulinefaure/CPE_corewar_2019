/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include <stdarg.h>
#include "my.h"
#include "parser.h"
#include "my_printf.h"

static void my_sprintf_args(char *stored_msg, char *msg, va_list args)
{
    print(&stored_msg, msg, args);
}

void context_push_error(context_t * context,
                        tokenizer_t * tokenizer, char *msg, ...)
{
    if (!context->error_stack) {
        context->error_stack_max = 16;
        context->error_stack = malloc(sizeof(parse_error_t) *
                                        context->error_stack_max);
    }
    if (context->error_stack_size < context->error_stack_max) {
        va_list args;
        va_start(args, msg);
        char stored_msg[255] = "";
        my_sprintf_args(stored_msg, msg, args);
        va_end(args);

        parse_error_t error = {
            .str = my_strdup(stored_msg),
            .line = tokenizer->lines,
        };
        context->error_stack[context->error_stack_size++] = error;
    }
}
