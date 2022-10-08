##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = main.c \
	  ppm.c \
	  text_file.c \
	  utils_text_file.c \
	  ../src/my_strtok.c \
	  ../src/open_file.c

OBJ = $(SRC:.c=.o)

NAME = giantman

INCLUDE = ../include

LIB = ../lib/my

CFLAGS = -I$(INCLUDE) -Wall -Wextra -g

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\tCC $<"

all:
	@echo "\033[1;37m\033[1;46m                    GIANTMAN\
	                    \033[0m"
	@$(MAKE) -s $(NAME)

make_lib:
		  make -C $(LIB)

$(NAME): make_lib $(OBJ)
		 gcc -g -o $(NAME) $(OBJ) -L$(LIB) -lmy
		 rm -f $(OBJ)

clean:
	   make clean -C $(LIB)
	   rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean all debug re clean tests_run make_lib $(NAME)
