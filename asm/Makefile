##
## EPITECH PROJECT, 2019
## Sample C Project
## File description:
## Makefile for Sample C Project
##

SHELL	=	bash

SRC_FILE	=	src/argument/file/file_manager.c	\
				src/argument/file/file_extension.c	\

SRC_ARGUEMENT	=	$(SRC_FILE)	\
					src/argument/argument_manager.c	\

SRC_CONTEXT	=	src/context/context_allocate_memory.c	\
				src/context/context_push_error.c	\

SRC_ENODE_NODE	=	src/enode_node/enode_node_parser.c	\

SRC_GRAPH	=	src/graph/graph_traverse.c	\

SRC_PARSER_LEXER	=	src/parser_lexer/get_token.c	\
						src/parser_lexer/parse_code_args.c	\
						src/parser_lexer/parse_code.c	\
						src/parser_lexer/parse_instruction.c	\
						src/parser_lexer/parse.c	\
						src/parser_lexer/peek_token.c	\
						src/parser_lexer/skip_whitespace.c	\
						src/parser_lexer/token_require.c	\

SRC 	=	src/asm_.c	\
			src/help.c	\
			src/asm_header.c	\
			src/code_generation.c	\
			src/conversion_instruction.c	\
			src/custom_callback.c	\
			src/extension.c	\
			src/label_position.c	\
			src/op.c	\
			src/print_n_reset_errors.c	\
			src/utilities.c	\
			$(SRC_ARGUEMENT)	\
			$(SRC_CONTEXT)	\
			$(SRC_ENODE_NODE)	\
			$(SRC_GRAPH)	\
			$(SRC_PARSER_LEXER)	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_SRC	=	tests/test_argument_manager.c	\
				tests/test_file_manager.c	\
				tests/test_file_extension.c	\
				tests/test_help.c	\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror

LFLAGS	=	-L./lib -lmy

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET	=	asm

TARGET_TEST	=	yoshida

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary with libs

$(TARGET) : build_lib build

build_lib: ## Compile the libs
	@$(MAKE) -C ./lib/libmy/ --silent
	@cp ./lib/libmy/libmy.a ./lib/libmy.a
	@cp ./lib/libmy/include/my.h ./include/my.h
	@cp ./lib/libmy/include/get_next_line.h ./include/get_next_line.h
	@cp ./lib/libmy/include/my_printf.h ./include/my_printf.h
	@cp ./lib/libmy/include/type.h ./include/type.h
	@cp ./lib/libmy/include/smart_ptr.h ./include/smart_ptr.h
	@cp ./lib/libmy/include/debug.h ./include/debug.h

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