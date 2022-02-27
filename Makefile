# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/02/27 14:47:33 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INCLUDE		= ./include
LIBFT		= ./libft
SRC_DIR		= ./src

SRC_FILES	= ft_printf.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAG		= -Wall -Wextra -Werror
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:	fclean all
