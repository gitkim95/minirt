/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_component.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:42 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/02 05:45:31 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_component.h"
#include "rt_figure.h"
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_parse.h"

void	parse_component(t_scene *scene, char **data)
{
	t_comp_init	init;

	if (rt_str_equals(data[0], "C"))
	{
		init.center = parse_to_coord(data[1]);
		init.dir = parse_to_coord(data[2]);
		init.fov = ft_atoi(data[3]);
		scene->cam = make_camera(init.center, init.dir, init.fov);
	}
	else if (rt_str_equals(data[0], "L"))
	{
		init.center = parse_to_coord(data[1]);
		init.bright = rt_atof(data[2]);
		init.color = parse_to_color(data[3]);
		scene->light = make_light(init.center, init.bright, init.color);
	}
	else if (rt_str_equals(data[0], "A"))
	{
		init.bright = rt_atof(data[1]);
		init.color = parse_to_color(data[2]);
		scene->amb_light = make_amb_light(init.bright, init.color);
	}
	else
		return ;
}
