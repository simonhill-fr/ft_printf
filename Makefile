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
			SRC/parse.c					\
			SRC/width_precision.c		\
			SRC/print_out.c 			\
			SRC/handle_general.c 		\
			SRC/handle_flags.c 			\
			SRC/handle_type_num1.c 		\
			SRC/handle_type_num2.c		\
			SRC/handle_type_char.c		\
			SRC/handle_length.c 		\
			SRC/handle_type_wint.c		\
			SRC/handle_type_wchar.c		\
			SRC/init_index_array.c 		\
			SRC/type_cast.c				\
			SRC/type_cast_2.c			\
			SRC/utilities.c				\
			

LIBFT	= libft/libft.a

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cp $(LIBFT) $(NAME)
	@ar r $(NAME) $(OBJ) 
#	@ranlib $(NAME)
#	@$(CC) -o $@ $^ $(LIBFT)

#main.o: $(NAME).h

%.o:%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	
fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
