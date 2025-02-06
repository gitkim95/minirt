/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 07:01:19 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COMPONENT_H
# define RT_COMPONENT_H

# include "rt_struct.h"

/* rt_component_light */
double		hit_light(t_light *light, t_ray *ray);
t_color		color_light(t_color color, t_coord hit_point, t_light *light, t_figure *fig);

/* rt_component */
t_camera	make_camera(t_coord center, t_rotate rotate, int fov);
t_light		make_light(t_coord center, double bright, t_color color);
t_amb_light	make_amb_light(double bright, t_color color);

#endif