/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:11:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/02 05:36:08 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"

#include "rt_parse.h"

void	parse_figure(t_fig_list *list, char **data)
{
	t_figure	*figure;

	figure = make_figure(data);
	if (figure)
		append_fig_list(list, figure);
}
