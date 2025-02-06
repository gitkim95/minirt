/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:49:45 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 20:39:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include <stdbool.h>

# define RT_WIDTH	800
# define RT_HEIGHT	600

# define RT_FIGURE		"cy\0pl\0sp"
# define RT_SCENE		"A\0C\0L"
# define RT_MLX_MODE	"translate\0rotate\0resize"

# define RT_RADIAN				0.0174533
# define RT_EPSILON				1e-6
# define RT_TOLERANCE_EPSILON	1e-5

typedef enum e_scene_type
{
	RT_A = 0,
	RT_C = 2,
	RT_L = 4,
	RT_F = 8,
}	t_scene_type;

typedef enum e_fig_type
{
	RT_CY = 0,
	RT_PL = 3,
	RT_SP = 6,
}	t_fig_type;

typedef enum e_mlx_mode
{
	RT_TRANSLATE = 0,
	RT_ROTATE = 10,
	RT_RESIZE = 17,
}	t_mlx_mode;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_axis
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}	t_axis;

typedef struct s_rotate
{
	t_vec	vector;
	t_axis	axis;
}	t_rotate;

typedef t_vec	t_coord;
typedef t_vec	t_color;

typedef struct s_ray
{
	t_coord	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_camera
{
	bool		exist;
	double		focal_length;
	double		vp_height;
	double		vp_width;
	double		fov;
	t_coord		center;
	t_rotate	rotate;
	t_vec		vp_w;
	t_vec		vp_u;
	t_vec		vp_v;
	t_vec		pixel_delta_u;
	t_vec		pixel_delta_v;
	t_vec		vp_upper_left;
	t_vec		pixel_zero_loc;
}	t_camera;

typedef struct s_light
{
	bool	exist;
	t_coord	center;
	double	bright;
	t_color	color;
	t_color	color_bright;
}	t_light;

typedef t_light	t_amb_light;

typedef struct s_figure
{
	t_fig_type		identifier;
	t_coord			center;
	t_vec			vector;
	double			diameter;
	double			height;
	t_color			color;
	t_rotate		rotate;
	double			(*calculate_hit)(struct s_figure *, t_ray *);
	t_vec			(*get_surf_normal)(t_coord, t_ray *, struct s_figure *);
	struct s_figure	*next;
}	t_figure;

typedef struct s_fig_list
{
	int			size;
	t_figure	*head;
	t_figure	*tail;
}	t_fig_list;

typedef struct s_scene
{
	t_camera	cam;
	t_light		light;
	t_amb_light	amb_light;
	t_fig_list	figures;
}	t_scene;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_trans_arg
{
	t_scene_type	type;
	void			*arg;
}	t_trans_arg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		img_data;
	t_scene		scene;
	t_trans_arg	trans_arg;
	t_mlx_mode	trans_mode;
}	t_mlx;

#endif