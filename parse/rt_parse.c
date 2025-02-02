/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/02 05:41:04 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include "rt_component.h"
#include "rt_error.h"
#include "rt_utils.h"
#include "libft.h"

#include "rt_parse.h"

static void	match_data_type(t_mlx *mlx, char **split_data);
static bool	valid_file_extension(char *file_path);

void	parse_data(t_mlx *mlx, char *file_path)
{
	int		fd;
	char	*read_line;
	char	**split_data;

	if (!valid_file_extension(file_path))
		exit(0);// error msg
	fd = open(file_path, O_RDONLY);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		split_data = ft_split(read_line, ' ');
		if (!split_data)
			exit_on_error(ENOMEM);// mem_leak_alert
		free(read_line);
		match_data_type(mlx, split_data);
		rt_free_split(split_data);
	}
}

static void	match_data_type(t_mlx *mlx, char **split_data)
{
	char	*identifier;

	identifier = split_data[0];
	if (rt_isupper(*identifier))
		parse_component(&(mlx->scene), split_data);
	else
		parse_figure(&(mlx->scene.figures), split_data);
}

static bool	valid_file_extension(char *file_path)
{
	char	**file_path_split;
	int		idx;
	bool	ret;

	ret = false;
	if (!rt_strcmp(file_path, "rt"))
		return (ret);
	file_path_split = ft_split(file_path, '.');
	if (!file_path_split)
		exit_on_error(ENOMEM);
	idx = 0;
	while (file_path_split[idx])
		idx++;
	if (!rt_strcmp(file_path_split[idx - 1], "rt"))
		ret = true;
	rt_free_split(file_path_split);
	return (ret);
}
