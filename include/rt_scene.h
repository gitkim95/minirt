/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:42:00 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 18:51:01 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

# include "rt_struct.h"

t_scene	make_scene(t_mlx *mlx, char *filepath);

#endif