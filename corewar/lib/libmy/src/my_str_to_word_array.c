/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Get an array of word from a string
*/

#include <stdlib.h>
#include "my.h"

static void go_to_next_word(char **str)
{
    for (; (**str == '\t' || **str == ' ') && **str; (*str)++);
}

static int word_len(char *str)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != ' ' && str[i] != '\t'; i++);
    return (i);
}

static int count_words(char *str)
{
    int words = 0;

    while (1) {
        go_to_next_word(&str);
        if (!*str)
            return (words);
        str += word_len(str);
        ++words;
    }
}

static int get_new_word(char *str, char **dest)
{
    int size_word = 0;

    go_to_next_word(&str);
    size_word = word_len(str);
    *dest = malloc(sizeof(char) * (size_word + 1));
    if (!(*dest))
        return (-1);
    my_wordcpy(*dest, str);
    return (0);
}

char **my_str_to_word_array(char *str)
{
    char **word_array = NULL;
    int is_get_success = 0;
    char *original_str = str;

    word_array = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!word_array)
        return (NULL);
    for (int i = 0; i < count_words(original_str); ++i) {
        is_get_success = get_new_word(str, word_array + i);
        if (is_get_success == -1)
            return (NULL);
        go_to_next_word(&str);
        str += word_len(str);
    }
    word_array[count_words(original_str)] = NULL;
    return (word_array);
}
