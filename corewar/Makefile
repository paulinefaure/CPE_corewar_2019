##
## EPITECH PROJECT, 2019
## Sample C Project
## File description:
## Makefile for Sample C Project
##

SHELL	=	bash

SRC 	=	src/corewar_.c	\
			src/argument/argument_manager.c	\
			src/help.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_SRC	=	tests/test_argument_manager.c	\
				tests/test_help.c	\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -pedantic

LFLAGS	=	-L./lib -lmy

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	corewar

TARGET_TEST	=	yoshida

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary with libs

$(TARGET) : build_lib build

build_lib: ## Compile the libs
	@$(MAKE) -C ./lib/libmy/ --silent
	@cp ./lib/libmy/libmy.a ./lib/libmy.a
	@cp ./lib/libmy/include/my.h ./include/my.h

%.o: %.c ## Compile the objects
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean_lib: ## Clean the libs
	@$(MAKE) -C ./lib/libmy/ --silent clean

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./lib/libmy/ --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib ## Clean the project
	@rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE) *.gcov
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(COVERAGE) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean ## Force clean the project
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all ## Force clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LFLAGS) $(TEST_LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLaunching tests...\e[0m]\n"
	@./$(TARGET_TEST)
	@gcov tests/*.gcno
	@gcov tests/*.gcda

re_tests: fclean tests_run ## Force clean then launch tests

valgrind: all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help valgrind