/*
** EPITECH PROJECT, 2019
** my
** File description:
** Header contains all functions prototyped
*/

#ifndef _MY_
#define _MY_

#include <stdio.h>
#include "type.h"
#include "get_next_line.h"
#include "my_printf.h"

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_char_isalpha(char str);
int my_char_isnum(char str);
char *my_strcat(char *dest, char const *src);
char *my_strcat_dup(char *str1, char *str2);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_charcat(char *dest, char src);
char *my_strchr(char *str, int c);

int fs_open_file(char const *filepath, char *perm);

void *my_memset(void *ptr, int x, int n);
void *my_memcpy(void *dest, const void *src, size_t len);

/****************************************************************************/

#endif