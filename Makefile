##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SHELL	=	bash

#-------------------------------------------------------------------------------

all: build_lib build ## Build the main binary with libs

build_lib: ## Compile the libs
	@$(MAKE) -C ./asm/ build_lib
	@$(MAKE) -C ./corewar/ build_lib

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@$(MAKE) -C ./asm/ build
	@$(MAKE) -C ./corewar/ build

clean_lib: ## Clean the libs
	@$(MAKE) -C ./asm/ clean_lib
	@$(MAKE) -C ./corewar/ clean_lib

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./asm/ fclean_lib
	@$(MAKE) -C ./corewar/ fclean_lib

clean: clean_lib ## Clean the project
	@$(MAKE) -C ./asm/ clean
	@$(MAKE) -C ./corewar/ clean

fclean: fclean_lib clean ## Force clean the project
	@$(MAKE) -C ./asm/ fclean
	@$(MAKE) -C ./corewar/ fclean

re:	fclean all ## Force clean then compile

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@$(MAKE) -C ./corewar/ tests_run
	@$(MAKE) -C ./asm/ tests_run

re_tests: fclean tests_run ## Force clean then launch tests

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help