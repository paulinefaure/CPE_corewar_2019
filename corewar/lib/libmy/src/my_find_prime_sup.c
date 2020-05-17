/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_find_prime_sup
*/

int my_find_prime_sup(int nb)
{
    float nnb = nb;

    if (nb <= 2 || nb % 2 == 0)
        return (my_find_prime_sup(nb + 1));
    for (int i = 3; i < nb; i += 2)
        if ((nnb / 2) == ((int)(nnb / 2)))
            return (my_find_prime_sup(nb + 1));
    return (nb);
}