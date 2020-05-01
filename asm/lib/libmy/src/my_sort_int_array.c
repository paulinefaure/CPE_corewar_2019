/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_sort_int_array
*/

static int is_sorted(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
        if (array[i] > array[i + 1])
            return (0);
    return (1);
}

int my_sort_int_array(int *array, int size)
{
    int tmp;

    while (is_sorted(array, size))
        for (int z = 0; z < size - 1; z++)
            if (array[z] > array[z + 1]) {
                tmp = array[z];
                array[z] = array[z + 1];
                array[z + 1] = tmp;
            }
    return (0);
}