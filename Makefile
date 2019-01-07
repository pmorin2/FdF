#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 16:34:48 by pmorin            #+#    #+#              #
#    Updated: 2018/12/12 17:57:45 by pmorin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fdf
LIB= libft/libft.a
FLAGS= -Wall -Wextra -Werror
CC= gcc
_GREEN= $'\x1b[32m'
SRCS= aff.c dy_nonull.c dy_nonull2.c dy_null.c fdf.c main.c mlx_set.c parsor.c\
	put.c free_map.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)
	@echo "${_GREEN}FdF is ready !${_GREEN}"

$(NAME): $(OBJS)
	@make -C libft/
	@gcc -o $@ $(OBJS) $(LIB) -lmlx -framework OpenGL -framework AppKit

.c.o:
	$(CC) -c $^ -o $@ $(FLAGS) -I libft/ -I minilix_macos/

.PHONY: clean

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f fdf
	rm -f libft/libft.a

re: fclean all
