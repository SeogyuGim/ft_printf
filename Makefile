# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seogkim <seogkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 16:51:00 by seogkim           #+#    #+#              #
#    Updated: 2020/03/01 14:14:23 by seogkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEADER	= incs

SRCS	= $(wildcard libft_srcs/*.c) $(wildcard printf_srcs/*.c)

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${HEADER}

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
