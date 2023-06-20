##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make
##

SRC	=	my_isneg.c			\
		my_strdup.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_swap.c			\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_putchar.c			\
		my_put_nbr.c			\
		my_is_prime.c			\
		my_strstr.c			\
		my_strcpy.c			\
		my_strncpy.c			\
		my_revstr.c			\
		my_strncmp.c			\
		my_strcmp.c			\
		my_getnbr.c			\
		my_find_prime_sup.c		\
		my_strcat.c			\
		my_showmem.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isalpha.c		\
		my_strcapitalize.c		\
		my_strlowcase.c			\
		my_strupcase.c			\
		my_strncat.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		printf_main.c			\
		printf_f1.c			\
		printf_f2.c			\
		printf_f3.c			\
		printf_f4.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a


$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean :
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean $(NAME)
