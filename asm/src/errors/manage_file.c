/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** open_file.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char *open_file(char const *filepath)
{
    struct stat file;
    int fs = open(filepath, O_RDONLY);
    int a = stat(filepath, &file);
    size_t size = (size_t) file.st_size;
    char *buffer = malloc(sizeof(char) * size);

    (void)a;
    if (buffer == NULL)
        return (NULL);
    if (fs == -1)
        return (NULL);
    read(fs, buffer, size);
    close(fs);
    return (buffer);
}

char **parsing_str(char **tab, char *buffer, int x)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        count++;
        if (buffer[i] == '\n') {
            tab[x] = malloc(sizeof(char) * (count));
            count = 0;
            x++;
        }
    }
    tab[x] = malloc(sizeof(char) * (count));
    x++;
    tab[x] = NULL;
    return tab;
}

char **parsing_buffer(char **tab, char *buffer)
{
    int count = 0;
    int x = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    count++;
    tab = malloc(sizeof(char *) * (count + 1));
    if (tab == NULL)
        return (NULL);
    tab = parsing_str(tab, buffer, x);
    return (tab);
}

char **copy_buffer(char **tab, char *buffer)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            tab[x][y] = '\0';
            x++;
            y = 0;
        } else {
            tab[x][y] = buffer[i];
            y++;
        }
        i++;
    }
    tab[x][y] = '\0';
    return (tab);
}

char **manage_file(char const *str)
{
    char *buffer = NULL;
    char **tab = NULL;

    buffer = open_file(str);
    if (buffer == NULL)
        return (NULL);
    tab = parsing_buffer(tab, buffer);
    if (tab == NULL)
        return (NULL);
    tab = copy_buffer(tab, buffer);
    if (tab == NULL)
        return (NULL);
    return (tab);
}