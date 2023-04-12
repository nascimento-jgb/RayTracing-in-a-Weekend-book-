/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:59 by helneff           #+#    #+#             */
/*   Updated: 2023/04/12 20:22:36 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_cylinder
{
	struct s_cylinder	*next;
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				dir_x;
	double				dir_y;
	double				dir_z;
	double				diameter;
	double				height;
	double				col_r;
	double				col_g;
	double				col_b;
}	t_cylinder;

typedef struct s_plane
{
	struct s_plane	*next;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			dir_x;
	double			dir_y;
	double			dir_z;
	double			col_r;
	double			col_g;
	double			col_b;
}	t_plane;

typedef struct s_sphere
{
	struct s_sphere	*next;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			diameter;
	double			col_r;
	double			col_g;
	double			col_b;
}	t_sphere;

typedef struct s_light
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	ratio;
	double	col_r;
	double	col_g;
	double	col_b;
}	t_light;

typedef struct s_ambient_light
{
	double	ratio;
	double	col_r;
	double	col_g;
	double	col_b;
}	t_ambient_light;

typedef struct s_camera
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	dir_x;
	double	dir_y;
	double	dir_z;
	double	fov;
}	t_camera;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient_light	ambient;
	t_light			light;
	t_sphere		*spheres;
	t_plane			*planes;
	t_cylinder		*cylinders;
}	t_scene;

typedef int	(*t_parser)(t_scene *scene, const char *elem);

t_scene	*parse_scene_file(int fd);

int		eat_whitespace(const char **elem);
int		eat_comma(const char **elem);
int		parse_num(const char **field, double *result);

int		parse_camera(t_scene *scene, const char *elem);
int		parse_ambient(t_scene *scene, const char *elem);
int		parse_light(t_scene *scene, const char *elem);
int		parse_sphere(t_scene *scene, const char *elem);
int		parse_plane(t_scene *scene, const char *elem);
int		parse_cylinder(t_scene *scene, const char *elem);

#endif
