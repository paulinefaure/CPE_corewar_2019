##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make an executable
##

CC = gcc

all: lib_make asm_make

lib_make:
	@make -sC lib/my

asm_make:
	@make -sC asm

.PHONY: clean
clean:
	@make clean -sC lib/my
	@make clean -sC asm/

.PHONY: fclean
fclean: clean
	@$(RM) -r vgcore*
	@make fclean -s -C lib/my
	@make fclean -sC asm/

.PHONY: re
re: fclean all

valgrind:
	valgrind --leak-check=full -s ./$(NAME)