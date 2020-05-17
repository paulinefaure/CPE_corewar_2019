/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** help
*/

#include <stdlib.h>
#include "my.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_name file in assembly language to be converted into");
    my_putstr("file_name.cor, an executable in the Virtual Machine.\n");
    return (EXIT_SUCCESS);
}