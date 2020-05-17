/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** errors.h
*/

#ifndef ERRORS_H_

#define ERRORS_H_

    // MANAGE FILE
        char *open_file(char const *filepath);
        char **parsing_buffer(char **tab, char *buffer);
        char **copy_buffer(char **tab, char *buffer);
        char **manage_file(char const *str);

    //MANAGE COMMENT
        int manage_comment(char **tab);

    //MANAGE QUOTES
        int check_quotes_comment(char *str);
        int check_quotes_name(char *str);

    //MANAGE NAME
        int manage_name(char **tab);

    //MANAGE ERRORS
        int manage_errors(char *str);

#endif