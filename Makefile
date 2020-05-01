##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make an executable
##

CC = gcc
TARGET_EXEC ?= asm

SRC_DIR = ./compilo

SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:%.c=%.o)

CFLAGS += -W -Wall $(if $(DEBUG),-g3) $(if $(DEBUG),-DDEBUG)
LDFLAGS = -Llib -lmy
INC_FLAGS = -Icompilo/include -Ilib/include
all: $(TARGET_EXEC)

lib_make:
	@make -s -C lib/my

$(TARGET_EXEC): lib_make $(OBJ)
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
	@make fclean -s -C lib/my

.PHONY: re
re: fclean all

valgrind:
	valgrind --leak-check=full -s ./$(NAME)