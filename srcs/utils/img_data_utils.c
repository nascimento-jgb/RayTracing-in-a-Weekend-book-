/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:54:07 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/14 11:16:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_mlx.h"

t_img_data	*create_img_data(int width, int height)
{
	t_img_data	*new;
	int			i;
	int			j;

	new = (t_img_data *)malloc(sizeof(t_img_data));
	if (!new)
		return (NULL);
	new->img_width = width;
	new->img_height = height;
	new->ref = (int **)malloc(sizeof(int) * width);
	if (!new->ref)
		return (NULL);
	i = -1;
	while (++i < width)
	{
		new->ref[i] = (int *)malloc(sizeof(int) * height);
		if (!new->ref[i])
			return (NULL);
		j = -1;
		while (++j < height)
			new->ref[i][j] = 0;
	}
	return (new);
}

void	free_img_data(t_img_data *data)
{
	int	i;

	i = -1;
	while (++i < data->img_width)
		free(data->ref[i]);
	free(data->ref);
	free(data);
}
