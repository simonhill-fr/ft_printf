# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shill <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/15 13:46:54 by shill             #+#    #+#              #
#    Updated: 2016/09/15 13:47:15 by shill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME 	= ft_printf
CC		= gcc

ifdef FLAGS
    ifeq ($(FLAGS), no)
        CFLAGS=
    endif
    ifeq ($(FLAGS), debug)
        CFLAGS= -Wall -Wextra -Werror -ansi -pedantic -g
    endif
else
    CFLAGS      = -Wall -Wextra -Werror
endif

SRC 	= main.c flags.c types_1.c 

LIBFT	= libft/libft.a

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $@ $^ $(LIBFT)

main.o: $(NAME).h

%.o:%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	
fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
