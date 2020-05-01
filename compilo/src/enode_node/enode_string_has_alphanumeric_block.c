/*
** EPITECH PROJECT, 2019
** EpiProjectGen
** File description:
** main
*/

#include <stdint.h>
#include "my.h"
#include "parser.h"

struct ast_data
{
    char *str;
    char *substr;
    int i;
    int *matches;
};

static int
second_check(struct ast_data data, int str_i, int substr_i)
{
    if (!data.substr[substr_i]) {
        if (substr_i > 0 &&
            (my_char_isalpha(data.substr[substr_i - 1]) ||
            my_char_isnum(data.substr[substr_i - 1]) ||
            data.substr[substr_i - 1] == '_')) {
            IF_THEN(my_char_isalpha(data.str[str_i]) ||
                    my_char_isnum(data.str[str_i]) ||
                    data.str[str_i] == '_', *data.matches = 0);
        }
        return (1);
    }
    if (data.str[str_i] != data.substr[substr_i]) {
        *data.matches = 0;
        return (1);
    }
    return (0);
}

static int
first_check(char *str, char *substr, int i)
{
    int matches = 0;

    if (str[i] == substr[0]) {
        matches = 1;
        for (int str_i = i + 1, substr_i = 1;; ++str_i, ++substr_i) {
            struct ast_data data = { str, substr, i, &matches };
            IF_THEN(second_check(data, str_i, substr_i), break);
        }
    }
    return (matches);
}

bool
enode_string_has_alphanumeric_block(char *string, char *substring)
{
    int matches = 0;

    if (string && substring) {
        for (int i = 0; string[i]; i++) {
            matches = first_check(string, substring, i);
            IF_THEN(matches, break);
        }
    }
    return matches;
}

int
enode_string_has_substring(char *string, char *substring)
{
    return enode_string_has_alphanumeric_block(string, substring);
}
