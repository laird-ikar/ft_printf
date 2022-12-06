# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/12/06 09:57:30 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT		=	./lib/libft/
SRC_DIR		=	./src/

SRC_FILES	= 			\
	ft_printf			\
	ft_parse			\
	ft_split_module		\
	ft_stringify		\
	checkers			\
	expend_arg			\
	parsers/c			\
	parsers/d			\
	parsers/great_x		\
	parsers/i			\
	parsers/p			\
	parsers/percent		\
	parsers/s			\
	parsers/u			\
	parsers/x			\
	parsers/apply_width	\
	parsers/update_flag

SRCS		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(LIBFT)libft.a
	cp $(LIBFT)libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT)libft.a:
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME) test

re:	fclean all

test: $(NAME) test.c
	$(CC) $(CFLAGS) -g -o test -L. -lftprintf test.c
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

.PHONY:	all clean fclean re
