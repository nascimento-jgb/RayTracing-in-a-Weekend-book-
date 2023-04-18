/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_plane(t_scene_data *scene, const char *elem)
{
	t_plane_data	*plane;

	plane = malloc(sizeof(t_plane_data));
	if (!plane)
		return (1);
	if (parse_num(&elem, &plane->pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &plane->pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &plane->pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &plane->dir_x) || eat_comma(&elem)
		|| parse_num(&elem, &plane->dir_y) || eat_comma(&elem)
		|| parse_num(&elem, &plane->dir_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &plane->col_r) || eat_comma(&elem)
		|| parse_num(&elem, &plane->col_g) || eat_comma(&elem)
		|| parse_num(&elem, &plane->col_b) || (*elem && *elem != '\n')
		|| plane->dir_x < -1 || plane->dir_x > 1
		|| plane->dir_y < -1 || plane->dir_y > 1
		|| plane->dir_z < -1 || plane->dir_z > 1
		|| plane->col_r < 0 || plane->col_r > 255
		|| plane->col_g < 0 || plane->col_g > 255
		|| plane->col_b < 0 || plane->col_b > 255)
		return (free(plane), 1);
	plane->next = scene->planes;
	scene->planes = plane;
	return (0);
}
