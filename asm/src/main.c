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

int32_t main(int32_t argc, char *argv[])
{
    switch (argument_manager(argc, argv))
    {
    case EXIT_FAILURE:
        return (EXIT_EPITECH);
    case EXIT_HELP:
        return (help());
    }
    return (asm_(argc, argv));
}