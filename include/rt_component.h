/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/29 19:07:29 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COMPONENT_H
# define RT_COMPONENT_H

# include "rt_struct.h"

# define RT_RADIAN	0.0174533

t_camera	make_camera(int width, int height, t_coord center, int fov);
t_light		make_light(t_coord center, double bright);
t_amb_light	make_amb_light(double bright, t_color color);

#endif