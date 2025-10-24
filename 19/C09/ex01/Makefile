# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regralin <regralin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 21:45:27 by regralin          #+#    #+#              #
#    Updated: 2025/08/26 12:57:49 by regralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
NAME	= libft.a
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
HEADERS	= includes
CFLAGS	+= -Wall -Wextra -Werror
RM	= rm -f
AR	= ar rc
OBJS	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
