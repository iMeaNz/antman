##
## EPITECH PROJECT, 2021
## Makefile DAY10
## File description:
## Makefile used to create lib
##

SRC	=	my_compute_power_it.c			\
		my_compute_square_root.c		\
		my_find_prime_sup.c				\
		my_getnbr_base.c				\
		my_getnbr.c						\
		my_is_prime.c					\
		my_isneg.c						\
		my_put_nbr.c					\
		my_putchar.c					\
		my_putnbr_base.c				\
		my_putstr.c						\
		my_revstr.c						\
		my_show_word_array.c			\
		my_sort_int_array.c				\
		my_str_isalpha.c				\
		my_str_islower.c				\
		my_str_isnum.c					\
		my_str_isprintable.c			\
		my_str_isupper.c				\
		my_str_to_word_array.c			\
		my_strcapitalize.c				\
		my_strcat.c						\
		my_strcmp.c						\
		my_strcpy.c						\
		my_strlen.c						\
		my_strlowcase.c					\
		my_strncat.c					\
		my_strncmp.c					\
		my_strncpy.c					\
		my_strstr.c						\
		my_strupcase.c					\
		my_swap_char.c					\
		my_swap.c						\
		is_alpha.c						\
		is_lower.c						\
		is_num.c						\
		is_upper.c						\
		my_printf/flags.c 				\
		my_printf/my_printf.c 			\
		my_printf/my_put_pointer.c 		\
		my_printf/my_put_printable_str.c\
		my_printf/stack.c 				\
		my_printf/utils_alloc.c 		\
		my_printf/utils_flag.c 			\
		my_printf/utils_misc.c 			\
		my_printf/utils_print.c 		\
		my_printf/utils_stack.c 		\
		my_printf/my_put_nbr_base_str.c \
		my_printf/sort_stack.c 			\
		my_printf/stack_field_width.c 	\
		my_printf/utils_deleting_node.c \
		my_printf/utils_str_2.c 		\
		my_printf/compute_percent.c 	\
		my_printf/compute_stack.c 		\
		my_printf/handle_bases.c 		\
		my_printf/utils_stack_2.c 		\
		my_printf/utils_stack_3.c 		\
		my_printf/blank.c 				\
		my_printf/positive.c 			\
		my_printf/neg.c 				\
		my_printf/zero.c				\
		init_int_array.c				\
		init_matrix.c					\
		init_str_array.c				\
		init_str.c

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\tCC $<"

all:
	@$(MAKE) -s $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
