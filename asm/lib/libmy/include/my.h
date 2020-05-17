/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Header file for libmy
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "get_next_line.h"
#include "my_printf.h"

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
long long int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *concat_params(int argc, char **argv);
int my_show_word_array(char const **tab);
char **my_str_to_word_array(char *str);
char *my_strdup(char const *src);
void my_put_nbr_base(int nb, char *base);
char *my_wordcpy(char *dest, char const *src);
int fs_open_file(char const *filepath, char *perm);
void *my_memset(void *ptr, int x, int n);
void *my_memcpy(void *dest, const void *src, size_t len);
int my_char_isalpha(char str);
int my_char_isnum(char str);
char *my_strcat_dup(char *str1, char *str2);
char *my_charcat(char *dest, char src);
char *my_strchr(char *str, int c);

#endif /* MY_H */