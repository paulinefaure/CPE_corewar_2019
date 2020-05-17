##
## EPITECH PROJECT, 2019
## libmy
## File description:
## The Makefile for libmy
##

SRC 	=	src/concat_params.c	\
			src/my_compute_power_rec.c	\
			src/my_compute_square_root.c	\
			src/my_find_prime_sup.c	\
			src/my_getnbr.c	\
			src/my_is_prime.c	\
			src/my_isneg.c	\
			src/my_put_nbr.c	\
			src/my_put_nbr_base.c	\
			src/my_putchar.c	\
			src/my_putstr.c	\
			src/my_revstr.c	\
			src/my_show_word_array.c	\
			src/my_showstr.c	\
			src/my_sort_int_array.c	\
			src/my_str_isalpha.c	\
			src/my_str_islower.c	\
			src/my_str_isnum.c	\
			src/my_str_isprintable.c	\
			src/my_str_isupper.c	\
			src/my_str_to_word_array.c	\
			src/my_strcapitalize.c	\
			src/my_strcat.c	\
			src/my_strcmp.c	\
			src/my_strcpy.c	\
			src/my_strdup.c	\
			src/my_strlen.c	\
			src/my_strlowcase.c \
			src/my_strncat.c	\
			src/my_strncmp.c	\
			src/my_strncpy.c	\
			src/my_strstr.c	\
			src/my_strupcase.c	\
			src/my_swap.c	\
			src/my_wordcpy.c	\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

TARGET	=	libmy.a

all:	$(TARGET)

$(TARGET): info $(OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@ar rc libmy.a $(OBJ)
	@printf "[\e[1;33mLinked\e[0m] % 33s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

info:
	@printf "\e[1;36mCFLAGS:\e[0m %s\n" $(CFLAGS)
	@printf "\e[1;36mTARGET:\e[0m %s\n" $(TARGET)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: clean
	@rm -f $(TARGET)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all