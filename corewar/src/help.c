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
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n-dump ");
    my_putstr("nbr_cycle dumps the memory after the nbr_cycle execution ");
    my_putstr("(if the round isn’t already over) with the following ");
    my_putstr("format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program’s number. By default, ");
    my_putstr("the first free number in the parameter order\n");
    my_putstr("-a load_address sets the next program’s loading address. ");
    my_putstr("When no address is specified, optimize the addresses so ");
    my_putstr("that the processes are as far away from each other as ");
    my_putstr("possible. The addresses are MEM_SIZE modulo.\n");
    return (EXIT_SUCCESS);
}