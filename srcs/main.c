/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 17:19:10 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <mlx.h>
#include <libft.h>

#include "parser.h"
#include "window.h"

#define IMG_WIDTH	1280
#define IMG_HEIGHT	720

static void	print_scene_values(const t_scene_data *scene)
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

static void	panic(int return_value, char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	exit(return_value);
}

int	main(void)
{
	static t_scene_data	scene;
	static t_window		window;

	if (parse_scene_file(&scene, "test.rt") == -1)
		panic(1, "Failed to parse scene file");
	if (init_mlx_window(&window, "MiniRT", IMG_WIDTH, IMG_HEIGHT) == -1)
		panic(1, "Failed to initialize MLX window");
	print_scene_values(&scene);
	mlx_loop(window.mlx_ptr);
	return (0);
}
