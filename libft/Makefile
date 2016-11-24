# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shill <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/26 18:17:39 by shill             #+#    #+#              #
#    Updated: 2016/09/24 12:27:37 by shill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: 
.PHONY: all clean fclean re

NAME 	= libft.a

SRC 	= \
		ft_isdigit.c	ft_memset.c		ft_strchr.c		ft_strlcat.c	\
		ft_strrchr.c	ft_isprint.c	ft_putchar.c	ft_strclr.c		\
		ft_strlen.c		ft_strsplit.c	ft_itoa.c		ft_putchar_fd.c	\
		ft_strcmp.c		ft_strmap.c		ft_strstr.c		ft_memalloc.c	\
		ft_putendl.c	ft_strcpy.c		ft_strmapi.c	ft_strsub.c		\
		ft_abs.c		ft_memccpy.c	ft_putendl_fd.c	ft_strdel.c		\
		ft_strncat.c	ft_strtrim.c	ft_atoi.c		ft_memchr.c		\
		ft_putnbr.c		ft_strdup.c		ft_strncmp.c	ft_tolower.c	\
		ft_bzero.c		ft_memcmp.c		ft_putnbr_fd.c	ft_strequ.c		\
		ft_strncpy.c	ft_toupper.c	ft_isalnum.c	ft_memcpy.c		\
		ft_putstr.c		ft_striter.c	ft_strnequ.c	ft_isalpha.c	\
		ft_memdel.c		ft_putstr_fd.c	ft_striteri.c	ft_strnew.c		\
		ft_isascii.c	ft_memmove.c	ft_strcat.c		ft_strjoin.c	\
		ft_strnstr.c	ft_pow.c		ft_printlist.c	ft_lstsize.c	\
		ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
		ft_lstiter.c	ft_lstmap.c		ft_strndup.c	ft_strnjoin.c	\
		get_next_line.c	ft_atoi_short.c	ft_itoa_base.c	ft_str_toupper.c \
		ft_putnbr_u.c	ft_utoa_base.c	ft_wputchar.c	ft_wputstr.c	\
		ft_wstrlen.c	ft_wstrdup.c	ft_wstrndup.c	ft_wstrcmp.c	\
		ft_wstr_bytes.c	ft_wchar_bytes.c	
		
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)

%.o:%.c
	@gcc -I. -Wall -Werror -Wextra -c $< -o $@
	
clean: 
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all
