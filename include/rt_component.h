/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 03:37:37 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COMPONENT_H
# define RT_COMPONENT_H

# include "rt_struct.h"

t_camera	make_camera(t_coord center, t_rotate rotate, int fov);
t_light		make_light(t_coord center, double bright, t_color color);
t_amb_light	make_amb_light(double bright, t_color color);

#endif