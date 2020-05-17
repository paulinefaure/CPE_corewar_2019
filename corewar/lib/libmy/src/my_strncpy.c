/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] && i < n; ++i)
        dest[i] = src[i];
    if (i != n)
        dest[i] = '\0';
    return (dest);
}