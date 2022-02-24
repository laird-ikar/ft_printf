# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:24:40 by bguyot            #+#    #+#              #
#    Updated: 2022/02/24 07:24:36 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isspace.c ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c
OBJS = ${SRCS:.c=.o}
SRCS_BONUS = ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	gcc -Wall -Wextra -Werror -c $(SRCS_BONUS) -I libft.h
	ar rcs $(NAME) $(OBJS_BONUS)
