/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:42:00 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 20:31:38 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

# include "rt_struct.h"

/* rt_scene_draw */
void	draw_scene(t_mlx *mlx);

/* rt_scene_parse */
t_scene	make_scene(t_mlx *mlx, char *filepath);

#endif