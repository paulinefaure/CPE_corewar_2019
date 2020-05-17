/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_file_manager
*/

#include <criterion/criterion.h>
#include "file.h"

Test(file_manager, good_file, .timeout = 1)
{
    int return_value = 0;
    char *file = "file.s";

    return_value = file_manager(file);
    cr_assert_eq(return_value, 0);
}

Test(file_manager, wrong_file, .timeout = 1)
{
    int return_value = 0;
    char *file = "file.szefsdfc.s";

    return_value = file_manager(file);
    cr_assert_eq(return_value, 1);
}