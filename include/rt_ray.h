/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:45:13 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 15:58:17 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAY_H
# define RT_RAY_H

# include "rt_struct.h"

typedef struct s_ray
{
	t_coord	origin;
	t_vec	direction;
}	t_ray;

t_coord	ray_at(t_ray *ray, double t);

#endif