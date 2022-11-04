# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 20:55:06 by vrsargsy          #+#    #+#              #
#    Updated: 2022/07/23 20:55:14 by vrsargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   so_long
SRCS		=	$(wildcard src/*.c)
OBJS		=	$(patsubst %.c, %.o, $(SRCS))

RM			=	rm -f
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I inc 
LINKERS		=	-l mlx -framework AppKit -framework OpenGL


# .DEFAULT_GOAL = all

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
    
re: fclean all

.PHONY: all clean fclean re
