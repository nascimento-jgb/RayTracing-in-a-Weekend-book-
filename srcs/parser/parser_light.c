/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_light(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->light.pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->light.ratio) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->light.col_r) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.col_g) || eat_comma(&elem)
		|| parse_num(&elem, &scene->light.col_b) || (*elem && *elem != '\n')
		|| scene->light.ratio < 0 || scene->light.ratio > 1
		|| scene->light.col_r < 0 || scene->light.col_r > 255
		|| scene->light.col_g < 0 || scene->light.col_g > 255
		|| scene->light.col_b < 0 || scene->light.col_b > 255)
		return (1);
	return (0);
}
