# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 09:05:28 by jonascim          #+#    #+#              #
#    Updated: 2023/04/07 15:32:21 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minirt
INCLUDE		= includes
LIBFT		= libft
MLX			= minilibx
SRC_DIR		= srcs/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -framework OpenGL -framework AppKit
RM			= rm -f

#Sources

SRC_FILES	=	main.c colors.c ray.c vector_utils.c vector_utils_2.c

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

###

all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@make -C $(MLX)
			@$(CC) $(CFLAGS) $(SRC) -o $(NAME)  -L. $(LIBFT)/libft.a -L. -lmlx $(MLXFLAGS)

clean:
			@make clean -C $(LIBFT)
			@make clean -C $(MLX)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) $(MLX)/libmlx.a

re:			fclean all

.PHONY:		all clean fclean re norm
