# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <salem@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 23:01:06 by sfreitas          #+#    #+#              #
#    Updated: 2021/03/27 14:42:44 by salem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = *.c
OBJS = *.o
CPARAMS = -c
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=70
CC = gcc
AR = ar
ARPARAMS = -rc

all: $(NAME)

$(NAME):
	$(CC) $(CPARAMS) $(CFLAGS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

bonus:	$(NAME)

noflags:
	$(CC) $(CPARAMS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

