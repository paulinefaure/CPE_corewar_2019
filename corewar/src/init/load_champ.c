/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** load_champ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "vm.h"

static void seek_n_read(char *filepath, cb_snr_t *callback)
{
    int fd = open(filepath, O_RDONLY);
    off_t offset = 0;
    int rd_size = 0;

    if (fd == -1) {
        callback->offset = -1;
        return;
    }
    offset = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    callback->buf = malloc(sizeof(char) * offset + 1);
    if (!callback->buf) {
        callback->offset = -1;
        return;
    }
    rd_size = read(fd, callback->buf, offset);
    callback->buf[rd_size] = '\0';
    close(fd);
    callback->offset = offset;
    return;
}

int load_champ(char *path, char memory[], champ_t *champion, size_t load_index)
{
    cb_snr_t callback;

    seek_n_read(path, &callback);
    if (callback.offset == -1)
        return (-1);
    for (int i = 0x8a7; i < callback.offset; ++i)
        memory[load_index + i - 0x8a7] = callback.buf[i];
    champion->cursor = load_index;
    return (0);
}