/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:44:59 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 16:54:46 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

#include "rt_ray.h"

t_coord	ray_at(t_ray *ray, double t)
{
	return (rt_vec_add(ray->origin, rt_vec_multiply(ray->direction, t)));
}
