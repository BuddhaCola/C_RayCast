# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:52:50 by wtaylor           #+#    #+#              #
#    Updated: 2021/02/27 20:12:05 by wtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRC		=	src/ft_exit.c src/ft_mapvalidation.c src/ft_move.c src/ft_my_mlx.c src/ft_parse.c src/ft_parse_utils.c\
			src/ft_parse_utils_2.c src/ft_raycaster.c src/ft_raycaster_utils.c src/ft_screenshot.c src/ft_sprites.c\
			src/ft_utils.c src/main.c src/get_next_line/get_next_line.c src/libft/ft_split.c

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

LIBX	=	minilibx_mms_20200219

LIBFT	=	src/libft

GNL		=	src/get_next_line

CC		=	gcc

%.o:%.c src/
	gcc $(FLAGS) -c -g $< -o $@
#вернуть FLAGS!

$(NAME):	$(OBJ)
			make -C $(LIBX)
			mv $(LIBX)/libmlx.dylib .
			make bonus -C $(LIBFT)
			$(CC) $(OBJ) $(LIBFT)/libft.a  -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address
			
all: $(NAME)

clean:
			rm -rf $(OBJ)
			make clean -C $(LIBFT)
			make clean -C $(LIBX)

fclean: clean
			rm -rf $(NAME) libmlx.dylib
			make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all