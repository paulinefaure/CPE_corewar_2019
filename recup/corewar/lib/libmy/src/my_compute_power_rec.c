/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_compute_power_rec
*/

static int recur(int nb, int p, int rec, int result)
{
    if (rec < p - 1) {
        int tmp = result;
        result *= nb;
        if ((result < 0) != (tmp < 0) && nb >= 0)
            return (0);
        else if ((result > 0) != (tmp < 0) && nb < 0)
            return (0);
        else
            return (recur(nb, p, rec + 1, result));
    }
    return (result);
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (recur(nb, p, 0, nb));
}