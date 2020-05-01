/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}