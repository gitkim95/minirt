/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/02 20:01:45 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_figure.h"

t_figure	*make_figure(char **figure_attr)
{
	t_figure	*figure;

	if (!*figure_attr)
		return (NULL);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_CY) == 0)
		figure = parse_cylinder(figure_attr);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_PL) == 0)
		figure = parse_plane(figure_attr);
	else if (rt_strcmp(figure_attr, RT_FIGURE + RT_SP) == 0)
		figure = parse_sphere(figure_attr);
	else
		figure = NULL;
	return (figure);
}
