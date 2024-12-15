NAME = libftprintf.a

FILE_NAME = ft_printf.c ft_printf_number.c ft_printf_string.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(FILE_NAME:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re : fclean all