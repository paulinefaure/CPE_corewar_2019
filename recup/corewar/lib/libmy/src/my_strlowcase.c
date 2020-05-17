/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i]; ++i)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    return (str);
}