NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror

SRC =  ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_nbr.c \
		ft_print_unsigned.c \
		ft_print_percent.c \
		ft_print_hex.c \
		ft_print_ptr.c

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -rf


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re