/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 19:26:43 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include "rt_figure.h"

/**
 * Plane: pl	0.0,0.0,-10.0	0.0,1.0,0.0		0,0,225
 * identifier: pl
 * x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
 * 3d normalized normal vector.
 * 		In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
 * R,G,B colors in range [0-255]: 0,0,225
 */

t_figure	*parse_plane(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_PL;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->vector = parse_to_coord(figure_attr[2]);
	figure->color = parse_to_color(figure_attr[3]);
	return (figure);
}

void	draw_plane(t_figure *figure)
{
	(void) figure;
	return ;
}
