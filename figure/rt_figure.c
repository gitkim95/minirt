/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:50:13 by hwilkim          ###   ########.fr       */
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

void	draw_figure(t_figure *figure, t_ray *ray)
{
	if (!figure)
		return ;
	else if (figure->diameter == RT_CY)
		draw_cylinder(figure);
	else if (figure->diameter == RT_PL)
		draw_plane(figure);
	else if (figure->diameter == RT_SP)
		hit_sphere(figure, ray);
}
