/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:59 by helneff           #+#    #+#             */
/*   Updated: 2023/04/17 12:38:23 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_cylinder_data
{
	struct s_cylinder_data	*next;
	double					pos_x;
	double					pos_y;
	double					pos_z;
	double					dir_x;
	double					dir_y;
	double					dir_z;
	double					diameter;
	double					height;
	double					col_r;
	double					col_g;
	double					col_b;
}	t_cylinder_data;

typedef struct s_plane_data
{
	struct s_plane_data	*next;
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				dir_x;
	double				dir_y;
	double				dir_z;
	double				col_r;
	double				col_g;
	double				col_b;
}	t_plane_data;

typedef struct s_sphere_data
{
	struct s_sphere_data	*next;
	double					pos_x;
	double					pos_y;
	double					pos_z;
	double					diameter;
	double					col_r;
	double					col_g;
	double					col_b;
}	t_sphere_data;

typedef struct s_light_data
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	ratio;
	double	col_r;
	double	col_g;
	double	col_b;
}	t_light_data;

typedef struct s_ambient_light_data
{
	double	ratio;
	double	col_r;
	double	col_g;
	double	col_b;
}	t_ambient_light_data;

typedef struct s_camera_data
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	dir_x;
	double	dir_y;
	double	dir_z;
	double	fov;
}	t_camera_data;

typedef struct s_scene_data
{
	t_camera_data			camera;
	t_ambient_light_data	ambient;
	t_light_data			light;
	t_sphere_data			*spheres;
	t_plane_data			*planes;
	t_cylinder_data			*cylinders;
}	t_scene_data;

typedef int	(*t_parser)(t_scene_data *scene, const char *elem);

t_scene_data	*parse_scene_file(int fd);

int		eat_whitespace(const char **elem);
int		eat_comma(const char **elem);
int		parse_num(const char **field, double *result);

int		parse_camera(t_scene_data *scene, const char *elem);
int		parse_ambient(t_scene_data *scene, const char *elem);
int		parse_light(t_scene_data *scene, const char *elem);
int		parse_sphere(t_scene_data *scene, const char *elem);
int		parse_plane(t_scene_data *scene, const char *elem);
int		parse_cylinder(t_scene_data *scene, const char *elem);

#endif
