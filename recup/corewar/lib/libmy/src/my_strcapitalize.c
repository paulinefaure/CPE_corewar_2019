/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (((str[i - 1] > 'Z' && str[i - 1] < 'a')
            || str[i - 1] > 'z' || str[i - 1] < 'A')
            && str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}