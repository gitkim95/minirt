/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 03:11:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_utils.h"

#include "rt_figure.h"

t_figure	*make_figure(char **figure_attr)
{
	t_figure	*figure;

	if (!*figure_attr)
		return (NULL);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_CY) == 0)
		figure = parse_cylinder(figure_attr);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_PL) == 0)
		figure = parse_plane(figure_attr);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_SP) == 0)
		figure = parse_sphere(figure_attr);
	else
		figure = NULL;
	return (figure);
}

double	hit_figure(t_figure *figure, t_ray *ray)
{
	if (!figure)
		return (-1.0);
	else if (figure->identifier == RT_CY)
		draw_cylinder(figure);
	else if (figure->identifier == RT_PL)
		return (hit_plane(figure, ray));
	else if (figure->identifier == RT_SP)
		return (hit_sphere(figure, ray));
	return (-1.0);
}

t_color	color_figure(t_ray *cam, t_light *light, t_figure *figure, double hit)
{
	if (hit < 0)
		return (light->color);
	else if (figure->identifier == RT_CY)
		draw_cylinder(figure);
	else if (figure->identifier == RT_PL)
		return (color_plane(cam, light, figure, hit));
	else if (figure->identifier == RT_SP)
		return (color_sphere(cam, light, figure, hit));
	return (light->color);
}
