##
## EPITECH PROJECT, 2019
## libmy
## File description:
## The Makefile for libmy
##

LIB_SAM		=	src/sam

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
			$(LIB_SAM)/debug.c	\
			$(LIB_SAM)/my_char_isalpha.c	\
			$(LIB_SAM)/my_char_isnum.c	\
			$(LIB_SAM)/my_charcat.c	\
			$(LIB_SAM)/io/fs_open_file.c	\
			$(LIB_SAM)/io/get_next_line.c	\
			$(LIB_SAM)/memory/my_memcpy.c	\
			$(LIB_SAM)/memory/my_memset.c	\
			$(LIB_SAM)/stdout/fsprintf.c	\
			$(LIB_SAM)/stdout/my_print_bases_prefix.c	\
			$(LIB_SAM)/stdout/my_print_bases.c	\
			$(LIB_SAM)/stdout/my_print_puts.c	\
			$(LIB_SAM)/stdout/my_printf.c	\
			$(LIB_SAM)/stdout/my_sprintf.c	\
			$(LIB_SAM)/stdout/puts/my_put_float.c	\
			$(LIB_SAM)/stdout/puts/my_put_long.c	\
			$(LIB_SAM)/stdout/puts/my_put_unsigned.c	\
			$(LIB_SAM)/stdout/puts/my_putbase.c	\
			$(LIB_SAM)/strings/my_strcat_dup.c	\
			$(LIB_SAM)/strings/my_strchr.c	\


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