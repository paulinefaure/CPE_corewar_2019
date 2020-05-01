/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] < 32)
            return (0);
    return (1);
}