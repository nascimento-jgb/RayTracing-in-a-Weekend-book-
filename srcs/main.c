/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 14:05:47 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "parser.h"

static void	print_scene_values(t_scene_data *scene)
{
	t_sphere_data	*sphere;
	t_plane_data	*plane;
	t_cylinder_data	*cylinder;

	printf("------------------------------------------\n");
	printf("Camera: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f)\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z,
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z,
		scene->camera.fov);
	printf("Ambient: (%.1f) (%.1f, %.1f, %.1f)\n",
		scene->ambient.ratio,
		scene->ambient.col.x, scene->ambient.col.x, scene->ambient.col.x);
	printf("Light: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n\n",
		scene->light.pos.x, scene->light.pos.y, scene->light.pos.z,
		scene->light.ratio,
		scene->light.col.x, scene->light.col.x, scene->light.col.x);
	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			sphere->pos.x, sphere->pos.y, sphere->pos.z,
			sphere->diameter,
			sphere->col.x, sphere->col.y, sphere->col.z);
		sphere = sphere->next;
	}
	plane = scene->planes;
	while (plane)
	{
		printf("Plane: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f)\n",
			plane->pos.x, plane->pos.y, plane->pos.z,
			plane->dir.x, plane->dir.y, plane->dir.z,
			plane->col.x, plane->col.y, plane->col.z);
		plane = plane->next;
	}
	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			cylinder->pos.x, cylinder->pos.y, cylinder->pos.z,
			cylinder->dir.x, cylinder->dir.y, cylinder->dir.z,
			cylinder->diameter,
			cylinder->height,
			cylinder->col.x, cylinder->col.y, cylinder->col.z);
		cylinder = cylinder->next;
	}
	printf("------------------------------------------\n");
}

int	main(void)
{
	int				scene_file;
	t_scene_data	*scene;

	scene_file = open("test.rt", O_RDONLY);
	scene = parse_scene_file(scene_file);
	print_scene_values(scene);
	free_scene(scene);
	return (0);
}
