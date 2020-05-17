/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_help
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

void redirect_all_std(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}

Test(help, help_display, .timeout = 1, .init=redirect_all_std)
{
    int return_value = 0;

    return_value = help();
    cr_assert_eq(return_value, 0);
}