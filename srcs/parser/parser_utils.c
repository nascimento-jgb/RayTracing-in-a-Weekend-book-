/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:50:31 by helneff           #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "parser.h"

int	eat_whitespace(const char **elem)
{
	if (**elem != ' ')
		return (1);
	while (**elem == ' ')
		(*elem)++;
	return (0);
}

int	eat_comma(const char **elem)
{
	if (**elem != ',')
		return (1);
	(*elem)++;
	return (0);
}

static double	convert_to_double(int integer, int decimal)
{
	double	fraction;

	fraction = decimal;
	while (fraction > 1)
		fraction *= 0.1;
	return (integer + fraction);
}

int	parse_num(const char **field, double *result)
{
	const int	sign = 1 - 2 * (**field == '-');
	int			integer;
	int			decimal;

	if (**field == '-' || **field == '+')
		(*field)++;
	integer = 0;
	while (ft_isdigit(**field))
		integer = integer * 10 + (*((*field)++) - '0');
	decimal = 0;
	if (**field == '.')
	{
		if (!ft_isdigit(*(++(*field))))
			return (1);
		while (ft_isdigit(**field))
			decimal = decimal * 10 + (*((*field)++) - '0');
	}
	if (**field != ',' && **field != ' ' && **field != '\n' && **field != '\0')
		return (1);
	*result = sign * convert_to_double(integer, decimal);
	return (0);
}
