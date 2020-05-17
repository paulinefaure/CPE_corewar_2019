/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_file_extension
*/

#include <criterion/criterion.h>
#include "file.h"

Test(file_manager, good_extension, .timeout = 1)
{
    int return_value = 0;
    char *file = "file.s";

    return_value = file_extension(file);
    cr_assert_eq(return_value, 0);
}

Test(file_manager, wrong_extension, .timeout = 1)
{
    int return_value = 0;
    char *file = "file.szefsdfc.s";

    return_value = file_extension(file);
    cr_assert_eq(return_value, 1);
}