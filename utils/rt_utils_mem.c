/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 20:44:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rt_utils.h"

void	rt_free_figure(t_fig_list *list)
{
	t_figure	*figure;
	t_figure	*tmp;

	figure = list->head;
	while (figure)
	{
		tmp = figure;
		figure = figure->next;
		free(tmp);
	}
}

void	rt_free_split(char **split)
{
	char	**start;

	if (!split)
		return ;
	start = split;
	while (*split)
	{
		free(*split);
		++split;
	}
	free(start);
}

bool	component_exist(t_scene *scene)
{
	return (scene->cam.exist && scene->light.exist && scene->amb_light.exist);
}
