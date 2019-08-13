# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 17:09:26 by swarner           #+#    #+#              #
#    Updated: 2019/07/15 09:50:47 by mevelyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = lib/
FLAGS = -Wall -Wextra -Werror -g
HEADERS = ./includes
SRCS = src/ft_printf.c src/engine.c src/parse.c src/argument.c src/size.c src/float.c src/types.c src/tools.c src/tools2.c src/argument2.c
OBJS = ft_printf.o engine.o parse.o argument.o size.o float.o types.o tools.o tools2.o argument2.o

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp lib/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: src/%.c
	@gcc $(FLAGS) -I $(HEADERS) -c $< -o $@

main: re
	@gcc -I $(HEADERS) -c src/main.c # $(FLAGS)
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