/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 13:35:00 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_figure.h"

t_figure	*make_figure(char **figure_attr)
{
	t_figure	*figure;

	if (!*figure_attr)
		return (NULL);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_CY) == 0)
		figure = parse_cylinder(figure_attr);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_PL) == 0)
		figure = parse_plane(figure_attr);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_SP) == 0)
		figure = parse_sphere(figure_attr);
	else
		figure = NULL;
	return (figure);
}

t_coord	parse_to_coord(char *str)
{
	t_coord	coord;
	char	**coord_split;

	coord_split = ft_split(str, ',');
	coord.x = rt_atof(coord_split[0]);
	coord.y = rt_atof(coord_split[1]);
	coord.z = rt_atof(coord_split[2]);
	rt_free_split(coord_split);
	return (coord);
}

int	parse_to_color(char *str)
{
	int		color;
	char	**color_split;

	color = 0;
	color_split = ft_split(str, ',');
	color += (ft_atoi(color_split[0]) << 8);
	color += (ft_atoi(color_split[1]) << 4);
	color += ft_atoi(color_split[2]);
	rt_free_split(color_split);
	return (color);
}
