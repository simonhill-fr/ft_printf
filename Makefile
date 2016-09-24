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

NAME 	= libftprintf.a
CC		= gcc

SRC 	= 	SRC/ft_printf.c 			\
			SRC/print_out.c 			\
			SRC/handle_general.c 		\
			SRC/handle_flags.c 			\
			SRC/handle_types_1.c 		\
			SRC/handle_length.c 		\
			SRC/init_index_array.c 	

LIBFT	= libft/libft.a

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
#	@make -C libft/ 	//UN-COMMENT
	@cp $(LIBFT) $(NAME)
	@ar r $(NAME) $(OBJ) 
#	@ranlib $(NAME)
#	@$(CC) -o $@ $^ $(LIBFT)

#main.o: $(NAME).h

%.o:%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
#	@make clean -C libft/ //UNCOMMENT
	@rm -f $(OBJ)
	
fclean: clean
#	@make fclean -C libft/ //UNCOMMENT
	@rm -f $(NAME)

re: fclean all
