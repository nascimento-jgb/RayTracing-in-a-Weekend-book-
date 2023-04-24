/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:28:47 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 10:08:35 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_list	*hitlst_new(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	return (new);
}

void	hitlst_add(t_list *list, void *obj, int obj_type)
{
	if (list->content)
	{
		while (list->next)
			list = list->next;
		list->next = hitlst_new();
		list = list->next;
	}
	list->content = hittable_new(obj, obj_type);
}

// void	hitlist_free(t_list *list)
// {
// 	if (list->next)
// 		free(list->next);
// 	hittable_free(list->content);
// 	free(list);
// }

int	hitlst_hit(t_list *list, t_hitlst_info *info)
{
	t_hittable	*hittable;
	int			hit_flag;

	hit_flag = FALSE;
	while (list && list->content)
	{
		hittable = (t_hittable *)(list->content);
		hittable->hit = sphere_hit(hittable->obj, info->ray, info, info->rec);
		if (hittable->hit == TRUE)
		{
			hit_flag = TRUE;
			info->t_max = info->rec->t;
		}
		list = list->next;
	}
	return (hit_flag);
}

