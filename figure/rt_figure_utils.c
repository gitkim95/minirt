/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:16:19 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/31 23:37:07 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_figure.h"

static double	normalize_color(double value);

void	append_fig_list(t_fig_list *list, t_figure *figure)
{
	if (list->size)
		list->tail->next = figure;
	else
		list->head = figure;
	list->tail = figure;
	++list->size;
}

t_coord	parse_to_coord(char *str)
{
	t_coord	coord;
	char	**coord_split;
	int		idx;

	coord_split = ft_split(str, ',');
	idx = 0;
	while (coord_split[idx])
		idx++;
	if (idx != 3)
		exit(0); // error, check for free
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
	int		idx;

	color_split = ft_split(str, ',');
	idx = 0;
	while (color_split[idx])
		idx++;
	if (idx != 3)
		exit(0); // error, check for free
	color.x = normalize_color(ft_atoi(color_split[0]));
	color.y = normalize_color(ft_atoi(color_split[1]));
	color.z = normalize_color(ft_atoi(color_split[2]));
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

static double	normalize_color(double value)
{
	value = fmin(value, 255);
	value = fmax(value, 0);
	return (value / 255.0);
}
