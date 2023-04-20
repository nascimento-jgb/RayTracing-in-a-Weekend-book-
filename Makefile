# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 09:05:28 by jonascim          #+#    #+#              #
#    Updated: 2023/04/20 15:15:42 by helneff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minirt
LIBFT		:= libft
INCLUDE		:= includes
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra
MLXFLAGS	:= -framework OpenGL -framework AppKit
RM			:= rm -f

SRC_DIR		:= srcs/
OBJ_DIR		:= srcs/object/
PARS_DIR	:= srcs/parser/
STRUCT_DIR	:= srcs/struct/
UTILS_DIR	:= srcs/utils/

SRC_FILES		:=	main.c

OBJ_FILES		:=	sky_image.c	sphere_init.c

PARS_FILES		:=	parser.c		parser_utils.c		parser_camera.c parser_ambient.c \
					parser_light.c	parser_sphere.c		parser_plane.c	parser_cylinder.c

STRUCT_FILES	:=	ray.c	vector.c	vector2.c	vector3.c

UTILS_FILES		:=	calc_utils.c	color_utils.c	draw_utils.c	img_data_utils.c \
					mlx_utils.c

SRC 		:= 	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ 		:= 	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
PARS 		:= 	$(addprefix $(PARS_DIR), $(PARS_FILES))
STRUCT 		:= 	$(addprefix $(STRUCT_DIR), $(STRUCT_FILES))
UTILS 		:= 	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(SRC) $(OBJ) $(PARS) $(STRUCT) $(UTILS) -o $(NAME) -I $(INCLUDE) -L. $(LIBFT)/libft.a -L. -lmlx $(MLXFLAGS)

clean:
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm
