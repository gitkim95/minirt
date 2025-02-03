/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 20:52:53 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COMPONENT_H
# define RT_COMPONENT_H

# include "rt_struct.h"

# define RT_UPPER_VEC	(t_vec){0, 1, 0}
# define RT_AXIS_X		(t_vec){1, 0, 0}

t_camera	make_camera(t_coord center, t_vec dir, int fov);
t_light		make_light(t_coord center, double bright, t_color color);
t_amb_light	make_amb_light(double bright, t_color color);

#endif