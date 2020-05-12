##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make an executable
##

CC = gcc
TARGET_EXEC ?= asm

SRC_DIR = .

SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:%.c=%.o)

CFLAGS += -W -Wall $(if $(DEBUG),-g3 -DDEBUG)
LDFLAGS = -L../lib -lmy
INC_FLAGS = -Iinclude -I../lib/include

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(INC_FLAGS) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32mCompiled \033[1;37m'$<'\033[m"

.PHONY: clean
clean:
	@$(RM) -r $(OBJ)

.PHONY: fclean
fclean: clean
	@$(RM) -r $(TARGET_EXEC)
	@$(RM) -r vgcore*

.PHONY: re
re: fclean all

valgrind:
	valgrind --leak-check=full -s ./$(TARGET_EXEC)