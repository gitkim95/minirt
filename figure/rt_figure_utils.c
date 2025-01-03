/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:16:19 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 15:26:17 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "libft.h"

#include "rt_figure.h"

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

t_color	parse_to_color(char *str)
{
	t_color	color;
	char	**color_split;

	color_split = ft_split(str, ',');
	color.x = ft_atoi(color_split[0]) / 255.0;
	color.y = ft_atoi(color_split[1]) / 255.0;
	color.z = ft_atoi(color_split[2]) / 255.0;
	rt_free_split(color_split);
	return (color);
}

int	to_rgb_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = 255.999 * color.x;
	g = 255.999 * color.y;
	b = 255.999 * color.z;
	return (r << 16 | g << 8 | b);
}
