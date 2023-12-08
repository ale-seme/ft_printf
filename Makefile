# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asemerar <asemerar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/27 16:11:41 by asemerar      #+#    #+#                  #
#    Updated: 2023/11/24 14:23:15 by asemerar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_putstring_r.c ft_putptr_r.c ft_putnbr_r.c ft_puthex_xup.c \
		ft_puthex_x.c ft_putchar_r.c ft_printf.c ft_putnbr_u_r.c ft_printf_chunks.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
# Targets
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re