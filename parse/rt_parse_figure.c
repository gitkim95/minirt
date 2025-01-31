/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:11:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/01 00:21:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"
#include "rt_struct.h"

#include "rt_parse.h"

void	set_figure_struct(t_fig_list *list, char **data, t_fig_type type)
{
	t_figure	*new_figure;

	if (type == RT_SP)
		new_figure = parse_sphere(data);
	else if (type == RT_PL)
		new_figure = parse_plane(data);
	else
		new_figure = parse_cylinder(data);
	append_fig_list(list, new_figure);
}
