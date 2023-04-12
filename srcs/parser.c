/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:14 by helneff           #+#    #+#             */
/*   Updated: 2023/04/12 19:06:10 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include "../includes/parser.h"

static void	error(size_t elem_count)
{
	ft_printf("Error\nFailed to parse elem #%d\n", elem_count);
	exit(1);
}

static void	skip_identifier(const char **elem)
{
	while (ft_isalpha(**elem))
		(*elem)++;
	while (**elem == ' ')
		(*elem)++;
}

static void	parse_element(t_scene *scene, const char *elem)
{
	static int				elem_count = 1;
	static const char		*identifiers[]
		= {"C ", "A ", "L ", "sp", "pl", "cy", NULL};
	static const t_parser	parsers[] = {
		parse_camera, parse_ambient, parse_light,
		parse_sphere, parse_plane, parse_cylinder
	};
	size_t					i;

	i = 0;
	while (identifiers[i] != NULL)
	{
		if (ft_strncmp(elem, identifiers[i], 2) == 0)
		{
			skip_identifier(&elem);
			if (parsers[i](scene, elem) != 0)
				error(elem_count);
			elem_count++;
			return ;
		}
		i++;
	}
	error(elem_count);
}

t_scene	*parse_scene_file(int fd)
{
	const char	*elem = get_next_line(fd);
	t_scene		*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	while (elem != NULL)
	{
		if (elem[0] != '\n')
			parse_element(scene, elem);
		elem = get_next_line(fd);
	}
	return (scene);
}
