# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regralin <regralin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 13:36:56 by regralin          #+#    #+#              #
#    Updated: 2025/08/27 20:23:32 by regralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
NAME	= do-op
SRCS	= ft_do-op.c ft_libft.c main.c
HEADERS	= ft.h
CFLAGS	+= -Wall -Wextra -Werror
RM	= rm -f
OBJS	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
