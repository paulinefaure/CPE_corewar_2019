/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_argument_manager
*/

#include <criterion/criterion.h>
#include "argument.h"

Test(argument_manager, help_exit, .timeout = 1)
{
    int return_value = 0;
    int ac = 2;
    char *av[2] = {"./buritos", "-h"};

    return_value = argument_manager(ac, av);
    cr_assert_eq(return_value, 42);
}

Test(argument_manager, good_argument, .timeout = 1)
{
    int return_value = 0;
    int ac = 2;
    char *av[2] = {"./hamburger", "file"};

    return_value = argument_manager(ac, av);
    cr_assert_eq(return_value, 0);
}

Test(argument_manager, not_enought_argument, .timeout = 1)
{
    int return_value = 0;
    int ac = 1;
    char *av[1] = {"./tacos"};

    return_value = argument_manager(ac, av);
    cr_assert_eq(return_value, 1);
}