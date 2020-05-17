/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** main
*/

#include <stdlib.h>
#include "macros.h"
#include "argument.h"
#include "prototype.h"

int main(int argc, char *argv[])
{
    switch (argument_manager(argc, argv))
    {
    case EXIT_FAILURE:
        return (EXIT_EPITECH);
    case EXIT_HELP:
        return (help());
    }
    return (corewar_(argc, argv));
}