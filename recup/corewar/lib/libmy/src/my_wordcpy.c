/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_wordcpy
*/

char *my_wordcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] && src[i] != ' ' && src[i] != '\t'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}