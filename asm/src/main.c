/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** main
*/

#include <stdlib.h>
#include "prototype.h"
#include "argument.h"
#include "parser.h"
#include "macros.h"
#include "errors.h"

int32_t main(int32_t argc, char *argv[])
{
    if (manage_errors(argv[1]) == 84)
        return (EXIT_EPITECH);
    switch (argument_manager(argc, argv))
    {
    case EXIT_FAILURE:
        return (EXIT_EPITECH);
    case EXIT_HELP:
        return (help());
    }
    return (asm_(argc, argv));
}