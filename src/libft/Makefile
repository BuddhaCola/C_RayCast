# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 20:32:08 by wtaylor           #+#    #+#              #
#    Updated: 2020/11/12 20:56:28 by wtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c \
ft_strtrim.c ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c ft_strlen.c \
ft_substr.c ft_calloc.c ft_itoa.c ft_memset.c ft_strchr.c ft_strmapi.c \
ft_tolower.c ft_isalnum.c ft_memccpy.c ft_putchar_fd.c ft_strdup.c \
ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putendl_fd.c \
ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcmp.c ft_putnbr_fd.c \
ft_strlcat.c ft_strrchr.c 

BONUS = ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c ft_lstadd_front.c\
ft_lstiter.c ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstsize.c\

NAME	=	libft.a

OBJ		=	$(SRC:.c=.o)

OBONUS	=	$(BONUS:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:	$(OBJ)	$(OBONUS)
		ar rc $(NAME) $(OBJ) $(OBONUS)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus