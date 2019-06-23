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
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes
SRCS = src/ft_printf.c src/engine.c src/parse.c src/argument.c
OBJS = ft_printf.o engine.o parse.o argument.o

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cp lib/libft.a ./$(NAME)
	@gcc $(FLAGS) -c -I $(HEADERS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

main: re all
	@gcc $(FLAGS) -I $(HEADERS) -c src/main.c
	@gcc main.o -L. -lftprintf -o ft_printf_test
	./ft_printf_test

leak: main
	valgrind --leak-check=full --show-leak-kinds=all -v ./ft_printf_test

main_clean:
	@/bin/rm -f main.o
	@/bin/rm -f ft_printf_test
clean:
	@make clean -C $(LIBFT)
	@/bin/rm -f $(OBJS)

fclean: clean main_clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all