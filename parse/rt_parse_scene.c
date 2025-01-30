/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:42 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/30 22:35:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <math.h>

#include "rt_parse.h"
#include "rt_struct.h"
#include "rt_figure.h"
#include "rt_component.h"
#include "rt_utils.h"
#include "rt_error.h"
#include "libft.h"

void	check_color_value(t_color *color)
{
	double	temp;
	
	temp = fmin(color->x, 255);
	color->x = fmax(temp, 0);
	temp = fmin(color->y, 255);
	color->y = fmax(temp, 0);
	temp = fmin(color->z, 255);
	color->z = fmax(temp, 0);	
}

void	set_ambient_lightning(t_amb_light *amb, char **data)
{
	double	bright;
	t_color	color;
	char	**temp_color;

	if (!ft_strchr(data[1], '.'));
		exit(0); // file_data_error;
	bright = rt_atof(data[1]);
	color = parse_to_color(data[2]);
	check_color_value(&color);
	amb->bright = bright;
	amb->color = color;
}

void	set_camera(t_camera *camera, char **data)
{
	
}

void	set_light(t_light *light, char **data)
{
	double	bright;
	t_color	color;
	char	**temp_color;

	if (!ft_strchr(data[1], '.'));
		exit(0); // file_data_error;
	bright = rt_atof(data[1]);
	color = parse_to_color(data[2]);
	check_color_value(&color);
	light->bright = bright;
	light->color = color;
}
void	set_scene_struct(t_scene *scene, char **data, t_scene_type type)
{
	if (type == RT_A)
		set_ambient_lightning(&(scene->amb_light), data);
	else if (type == RT_C)
		set_camera(&(scene->cam), data);
	else
		set_light(&(scene->light), data);
}
