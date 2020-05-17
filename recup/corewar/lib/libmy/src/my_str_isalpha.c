/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] <= 'Z' && str[i] >= 'A')
            || (str[i] <= 'z' && str[i] >= 'a')
            || (str[i] <= '9' && str[i] >= '0')))
            return (0);
    return (1);
}