/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:41:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 04:22:07 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_component.h"
#include "rt_figure.h"
#include "rt_utils.h"
#include "libft.h"

#include "rt_scene.h"

/* todo, delete this static function */
static	t_figure	*tmp_figure(void);
static	t_figure	*tmp_figure2(void);

t_scene	make_scene(t_mlx *mlx, char *filepath)
{
	t_scene	*scene;

	(void) filepath;
	scene = &mlx->scene;
	scene->cam = make_camera(RT_WIDTH, RT_HEIGHT, (t_coord){0, 0, 0});
	scene->light = make_light((t_coord){2, 2, 2}, 0.7);
	scene->amb_light = make_amb_light(0.1, (t_color){1, 1, 1});
	append_fig_list(&scene->figures, tmp_figure());
	append_fig_list(&scene->figures, tmp_figure2());
	return (*scene);
}

static	t_figure	*tmp_figure(void)
{
	char		**split;
	t_figure	*figure;

	split = ft_split("sp   0.0,0.0,-1.5   1.5   10,0,255", ' ');
	figure = make_figure(split);
	rt_free_split(split);
	return (figure);
}

static	t_figure	*tmp_figure2(void)
{
	char		**split;
	t_figure	*figure;

	split = ft_split("sp   1.0,0.0,-2.0   1.0   255,0,10", ' ');
	figure = make_figure(split);
	rt_free_split(split);
	return (figure);
}
