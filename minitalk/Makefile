NAME = ft_minitalk.a
HDRS = ft_minitalk.h
CC = cc
FLAGS = -Wall -Werror -Wextra -g
CLIENT = client
SERVER = server

LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(LIBFT) $(PRINTF) $(CLIENT) $(SERVER)

$(LIBFT):
	@if [ ! -f $(LIBFT) ]; then make --no-print-directory -C $(LIBFT_DIR); fi

$(PRINTF):
	@if [ ! -f $(PRINTF) ]; then make --no-print-directory -C $(PRINTF_DIR); fi

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)
	@echo "\033[1;32m [Success] client created.\033[1;1m"

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "\033[1;32m [Success] server created.\033[1;1m"

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	@echo "\033[1;31m [Deleting] object files deleted.\033[1;1m"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -rf $(CLIENT) $(SERVER)
	@echo "\033[1;31m [Deleting] .a deleted.\033[1;1m"

re: fclean all

.PHONY: all clean fclean re
