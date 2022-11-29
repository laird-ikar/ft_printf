# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/11/29 08:59:24 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INCLUDE		= ./include/
LIBFT		= ./lib/libft/
SRC_DIR		= ./src/

SRC_FILES	= 			\
	ft_printf			\
	ft_parse			\
	ft_split_module	\
	ft_stringify

SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)libft.a
	ar rcs $(NAME) $(OBJS)

$(LIBFT)libft.a:
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
