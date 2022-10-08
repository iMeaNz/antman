##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

LIB = lib/my

all:
	 @echo "\033[1;37m\033[1;42m                      LIB\
	                        \033[0m"
	 @$(MAKE) -s -C $(LIB)
	 @$(MAKE) -s -C antman
	 @$(MAKE) -s -C giantman

clean:
		make clean -C $(LIB)
		make clean -C antman
		make clean -C giantman

fclean:
		make fclean -C $(LIB)
		make fclean -C antman
		make fclean -C giantman
		rm -f $(NAME)

re: fclean
	make re -C antman
	make re -C giantman

.PHONY: fclean all debug re clean make_lib $(NAME)
