# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/11/30 14:18:11 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INCLUDE		= ./include/
LIBFT		= ./lib/libft/
SRC_DIR		= ./src/

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
	parsers/x

SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS) libft.a
	ar rcs $(NAME) $(OBJS)

libft.a:
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)libft.a $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re:	fclean all

test: re
	$(CC) $(CFLAGS) -o test -L. -lftprintf test.c

test_fclean: fclean
	$(RM) test

test_re: test_fclean test

.PHONY:	all clean fclean re
