/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:05 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 07:29:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_hitlst_info	*hitlst_info_new(t_ray *ray)
{
	t_hitlst_info	*new;

	new = (t_hitlst_info *)malloc(sizeof(t_hitlst_info));
	if (!new)
		return (NULL);
	new->ray = ray;
	new->t_min = 0.001;
	new->t_max = 1000000000;
	new->rec = hit_record_new();
	return (new);
}
