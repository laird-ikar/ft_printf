# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:18:47 by bguyot            #+#    #+#              #
#    Updated: 2022/12/08 08:07:19 by bguyot           ###   ########.fr        #
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
	parsers/f			\
	parsers/apply_width	\
	parsers/update_flag

SRCS		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJ_COLOR		=	"\e[38;5;147m"
CLN_COLOR		=	"\e[38;5;124m"
BIN_COLOR		=	"\e[38;5;129m"

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(LIBFT)libft.a
	@cp $(LIBFT)libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf $(BIN_COLOR)"\t"$(NAME)" \t\t\t[ ✓ ]\n\e[0m"

$(LIBFT)libft.a:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(OBJ_COLOR)"\t"$@"\n\e[0m"

clean:
	@$(MAKE) fclean -C $(LIBFT)
	@$(RM) $(OBJS)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" objects\t[ ✓ ]\n\e[0m"

fclean: clean
	@$(RM) $(NAME)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" binary\t[ ✓ ]\n\e[0m"

re:	fclean all

.PHONY:	all clean fclean re
