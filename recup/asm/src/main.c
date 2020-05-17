/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** main
*/

#include <stdlib.h>
#include "prototype.h"
#include "argument.h"
#include "macros.h"

int main(int argc, char *argv[])
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