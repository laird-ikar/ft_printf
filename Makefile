# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/03/09 12:04:35 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INCLUDE		= ./include/
LIBFT		= ./libft/
SRC_DIR		= ./src/

SRC_FILES	= ft_printf.c ft_printf_int.c ft_printf_percent.c ft_printf_ptr.c\
	ft_printf_str.c ft_printf_uint.c ft_printf_upper_xint.c ft_printf_xint.c\
	ft_printf_chr.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re:	fclean all

test: re
	$(CC) $(FLAGS) -o test -L. -lftprintf test.c

test_fclean: fclean
	$(RM) test

test_re: test_fclean test

.PHONY:	all clean fclean re
