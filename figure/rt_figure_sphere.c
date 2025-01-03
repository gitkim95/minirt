/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 15:49:29 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_figure.h"

/**
 * Sphere: sp	0.0,0.0,20.6	12.6	10,0,255
 * identifier: sp
 * x,y,z coordinates of the sphere center: 0.0,0.0,20.6
 * the sphere diameter: 12.6
 * R,G,B colors in range [0-255]: 10, 0, 255
 */

t_figure	*parse_sphere(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_SP;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->diameter = rt_atof(figure_attr[2]);
	figure->color = parse_to_color(figure_attr[3]);
	return (NULL);
}

void	draw_sphere(t_figure *figure)
{
	(void) figure;
	return ;
}
