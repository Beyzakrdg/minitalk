NAME_CLIENT = client
NAME_SERVER = server

FILE_NAME_CLIENT = client.c
FILE_NAME_SERVER = server.c

PRINTF_DIR = ./ft_printf
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(PRINTF_DIR)

OBJ_CLIENT = $(FILE_NAME_CLIENT:.c=.o)
OBJ_SERVER = $(FILE_NAME_SERVER:.c=.o)

all: $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME_CLIENT): $(OBJ_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) -o $(NAME_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	rm -f $(FT_PRINTF)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all
