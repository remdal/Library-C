# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regralin <regralin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 23:13:46 by regralin          #+#    #+#              #
#    Updated: 2025/08/24 23:14:58 by regralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CF = -Wall -Wextra 
SRCS = $(wildcard ./*.c)
OBJS = $(patsubst ./%.c, ./%.o, $(SRCS))

TARGET = rush-02

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CF) $^ -o $@

./%.o: ./%.c
	$(CC) $(CF) -c $< -o $@

fclean:
	@rm -rf $(OBJS)
	@rm -f $(TARGET)


.PHONY: all fclean
