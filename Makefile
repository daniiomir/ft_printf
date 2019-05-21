# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 17:09:26 by swarner           #+#    #+#              #
#    Updated: 2019/05/16 17:09:28 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = lib/libft.a
FLAGS = -Wall -Wextra -Werror -c
HEADERS = ./includes
SRCS = ft_printf.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cp $(LIBFT) ./$(NAME)
	@gcc $(FLAGS) -I $(HEADERS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

main:  re all
	@gcc -c main.c
	@gcc main.o -L. -lftprintf -o ft_printf

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all