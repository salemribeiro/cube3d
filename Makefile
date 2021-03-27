# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salem <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 09:08:01 by salem             #+#    #+#              #
#    Updated: 2021/01/20 20:29:00 by salem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
FLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g
H_CUB 	= -I ./sources
H_GNL 	= -I ./sources/gnl
H_LIB 	= -I ./sources/libft
H_PRT	= -I ./sources/ft_printf/headers
NAME	= cub3D
PSRCS	= ./sources/
LIBA	= ./sources/gnl/get_next_line.a ./sources/libft/libft.a ./sources/ft_printf/libftprintf.a

SRCS	=	read_file.c \
			errors.c \
			header_treatment.c \
			get_map.c \
			clear_data.c \
			map_normalize.c \
			map_treatment.c \
			color_treatment.c

CSRCS = $(patsubst %.c, $(PSRCS)%.c, $(SRCS))

all : $(NAME)

$(NAME) : libft gnl ft_printf
	$(CC) $(FLAGS) -o cub3D $(CSRCS) main.c $(LIBA) $(H_CUB) $(H_GNL) $(H_LIB) $(H_PRT)

libft :
	$(MAKE) -C ./sources/libft all

gnl :	
	$(MAKE) -C ./sources/gnl all

ft_printf:
	$(MAKE) -C ./sources/ft_printf all

clean :
	$(MAKE) -C ./sources/libft clean
	$(MAKE) -C ./sources/gnl clean
	$(MAKE) -C ./sources/ft_printf clean 

fclean : clean
	$(MAKE) -C sources/libft fclean
	$(MAKE) -C sources/gnl fclean
	$(MAKE) -C sources/ft_printf fclean
	rm ./cub3D

re : fclean all

test : all
	./cub3D ./cub3d.cub