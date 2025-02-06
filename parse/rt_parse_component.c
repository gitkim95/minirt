/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_component.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:42 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/06 22:43:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_component.h"
#include "rt_figure.h"
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_parse.h"

static void	component_camera(t_scene *scene, char **data);
static void	component_light(t_scene *scene, char **data);
static void	component_amb_light(t_scene *scene, char **data);

void	parse_component(t_scene *scene, char **data)
{
	if (rt_str_equals(data[0], "C"))
	{
		if (data_count(data) != 4)
			return ;
		component_camera(scene, data);
	}
	else if (rt_str_equals(data[0], "L"))
	{
		if (data_count(data) != 4)
			return ;
		component_light(scene, data);
	}
	else if (rt_str_equals(data[0], "A"))
	{
		if (data_count(data) != 3)
			return ;
		component_amb_light(scene, data);
	}
	else
		return ;
}

static void	component_camera(t_scene *scene, char **data)
{
	t_comp_init	init;

	init.center = parse_to_coord(data[1]);
	init.rotate.vector = v_unit(parse_to_coord(data[2]));
	init.rotate.axis = get_default_axis();
	init.fov = ft_atoi(data[3]);
	scene->cam = make_camera(init.center, init.rotate, init.fov);
}

static void	component_light(t_scene *scene, char **data)
{
	t_comp_init	init;

	init.center = parse_to_coord(data[1]);
	init.bright = rt_atof(data[2]);
	init.color = parse_to_color(data[3]);
	scene->light = make_light(init.center, init.bright, init.color);
}

static void	component_amb_light(t_scene *scene, char **data)
{
	t_comp_init	init;

	init.bright = rt_atof(data[1]);
	init.color = parse_to_color(data[2]);
	scene->amb_light = make_amb_light(init.bright, init.color);
}
