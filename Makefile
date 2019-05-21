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
LIBFT = lib/
FLAGS = -Wall -Wextra -Werror -c
HEADERS = ./includes
SRCS = src/ft_printf.c
OBJS = ft_printf.o

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cp lib/libft.a ./$(NAME)
	@gcc $(FLAGS) -I $(HEADERS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

main:  re all
	@gcc -c src/main.c
	@gcc main.o -L. -lftprintf -o ft_printf

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all