/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/13 13:14:21 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#include "../../includes/libft.h"

int	parse_sphere(t_scene *scene, const char *elem)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (1);
	if (parse_num(&elem, &sphere->pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->diameter) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->col_r) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col_g) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col_b) || (*elem && *elem != '\n')
		|| sphere->col_r < 0 || sphere->col_r > 255
		|| sphere->col_g < 0 || sphere->col_g > 255
		|| sphere->col_b < 0 || sphere->col_b > 255)
		return (free(sphere), 1);
	sphere->next = scene->spheres;
	scene->spheres = sphere;
	return (0);
}
