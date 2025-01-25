/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:41:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/26 16:53:23 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_component.h"
#include "rt_figure.h"
#include "rt_utils.h"
#include "libft.h"

#include "rt_scene.h"

static	t_figure	*tmp_figure(void);

t_scene	make_scene(t_mlx *mlx, char *filepath)
{
	t_scene	*scene;

	(void) filepath;
	scene = &mlx->scene;
	scene->cam = make_camera(mlx->width, mlx->height, (t_coord){0, 0, 0});
	scene->light = make_light((t_coord){2, 2, 2}, 0.7);
	scene->amb_light = make_amb_light(0.2, (t_color){1, 1, 1});
	append_fig_list(&scene->figures, tmp_figure());
	return (*scene);
}

static	t_figure	*tmp_figure(void)
{
	char		**split;
	t_figure	*figure;

	split = ft_split("sp   0.0,0.0,-1.0   1.0   10,0,255", ' ');
	figure = make_figure(split);
	rt_free_split(split);
	return (figure);
}
