/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/30 21:12:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#include "rt_parse.h"
#include "rt_struct.h"
#include "rt_error.h"
#include "rt_utils.h"
#include "libft.h"

void	valid_data_type(t_mlx *mlx, char **split_data)
{
	if (rt_strcmp(split_data[0], "A"))
		set_scene_struct(&(mlx->scene), split_data, RT_A);
	else if (rt_strcmp(split_data[0], "C"))
		set_scene_struct(&(mlx->scene), split_data, RT_C);
	else if (rt_strcmp(split_data[0], "L"))
		set_scene_struct(&(mlx->scene), split_data, RT_L);
	else if (rt_strcmp(split_data[0], "sp"))
		set_scene_struct(&(mlx->scene.figures), split_data, RT_SP);
	else if (rt_strcmp(split_data[0], "pl"))
		set_scene_struct(&(mlx->scene.figures), split_data, RT_PL);
	else if (rt_strcmp(split_data[0], "cy"))
		set_scene_struct(&(mlx->scene.figures), split_data, RT_CY);
	else
		return ;
}

bool	valid_file_extension(char *file_path)
{
	char	**file_path_split;
	int		idx;
	bool	ret;

	ret = false;
	if (rt_strcmp(file_path, "rt"))
		return (ret);
	file_path_split = ft_split(file_path, '.');
	if (!file_path_split)
		exit_on_error(ENOMEM);
	idx = 0;
	while (file_path_split[idx])
		idx++;
	if (rt_strcmp(file_path_split[idx - 1], "rt"));
		ret = true;
	rt_free_split(file_path_split);
	return (ret);
}

void	parse_data(t_mlx *mlx, char *file_path)
{
	int		idx;
	int		fd;
	char	*read_line;
	char	**split_data;

	if (!valid_file_extension(file_path))
		exit(0);// error msg
	fd = open(file_path, O_RDONLY);
	idx = 0;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		split_data = ft_split(read_line, ' ');
		if (split_data)	
			exit_on_error(ENOMEM);// mem_leak_alert
		free(read_line);
		valid_data_type(mlx, split_data);
		rt_free_split(split_data);
	}
}
