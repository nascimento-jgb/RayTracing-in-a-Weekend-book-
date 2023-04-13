/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:16:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_mlx.h"

#include <stdlib.h>
#include <fcntl.h>

#include "../includes/parser.h"
#include <stdio.h>

static void	print_scene_values(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	printf("------------------------------------------\n");
	printf("Camera: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f)\n",
		scene->camera.pos_x, scene->camera.pos_y, scene->camera.pos_z,
		scene->camera.dir_x, scene->camera.dir_y, scene->camera.dir_z,
		scene->camera.fov);
	printf("Ambient: (%.1f) (%.1f, %.1f, %.1f)\n",
		scene->ambient.ratio,
		scene->ambient.col_r, scene->ambient.col_r, scene->ambient.col_r);
	printf("Light: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n\n",
		scene->light.pos_x, scene->light.pos_y, scene->light.pos_z,
		scene->light.ratio,
		scene->light.col_r, scene->light.col_r, scene->light.col_r);
	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			sphere->pos_x, sphere->pos_y, sphere->pos_z,
			sphere->diameter,
			sphere->col_r, sphere->col_g, sphere->col_b);
		sphere = sphere->next;
	}
	plane = scene->planes;
	while (plane)
	{
		printf("Plane: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f)\n",
			plane->pos_x, plane->pos_y, plane->pos_z,
			plane->dir_x, plane->dir_y, plane->dir_z,
			plane->col_r, plane->col_g, plane->col_b);
		plane = plane->next;
	}
	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			cylinder->pos_x, cylinder->pos_y, cylinder->pos_z,
			cylinder->dir_x, cylinder->dir_y, cylinder->dir_z,
			cylinder->diameter,
			cylinder->height,
			cylinder->col_r, cylinder->col_g, cylinder->col_b);
		cylinder = cylinder->next;
	}
	printf("------------------------------------------\n");
}

int	main(void)
{
	t_mlx	prog;

	int	scene_file = open("test.rt", O_RDONLY);
	t_scene	*scene = parse_scene_file(scene_file);
	print_scene_values(scene);
	return (0);
}
