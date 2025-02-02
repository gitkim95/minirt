/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/02 20:12:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
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
		exit_on_error(NULL, RT_ERR_FILE_EXTENSION);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit_on_error(NULL, RT_ERR_OPEN);
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		split_data = ft_split(read_line, ' ');
		if (!split_data)
		{
			free(read_line);
			exit_on_error(mlx, RT_ERR_MEM);
		}
		free(read_line);
		match_data_type(mlx, split_data);
		rt_free_split(split_data);
	}
	close(fd);
}

static void	match_data_type(t_mlx *mlx, char **split_data)
{
	char	*identifier;

	identifier = split_data[0];
	if (rt_isupper(*identifier))
		parse_component(&(mlx->scene), split_data);
	else
		parse_figure(&(mlx->scene.figures), split_data);
	if (rt_errno(RT_ERRNO_GET) > 0)
		exit_on_error(mlx, rt_errno(RT_ERRNO_GET));
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
		exit_on_error(NULL, RT_ERR_MEM);
	idx = 0;
	while (file_path_split[idx])
		idx++;
	if (!rt_strcmp(file_path_split[idx - 1], "rt"))
		ret = true;
	rt_free_split(file_path_split);
	return (ret);
}
