/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:50:57 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 20:43:49 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// The rest of the chars

void	ft_assign_images_to_map_bonus(t_huge *data, int y, int x, char c)
{
	if (c == 'P')
	{
		data->p_coord_x = x;
		data->p_coord_y = y;
		ft_choose_which_hero(data, x, y);
	}
	else if (c == 'F')
	{
		data->f_coord_x = x;
		data->f_coord_y = y;
		ft_choose_which_foe(data, x, y);
	}
	else if (c == 'S')
	{
		data->f_coord_x = x;
		data->f_coord_y = y;
		ft_choose_which_foe(data, x, y);
	}
	ft_game_over(data, 'a');
}

// Prints the proper images according to the char scouted

void	ft_assign_images_to_map(t_huge *data, int y, int x, char c)
{
	if (c == '1')
		ft_image_push(data, data->wall, x, y);
	else if (c == '0')
		ft_image_push(data, data->grass, x, y);
	else if (c == 'E')
		ft_image_push(data, data->exit, x, y);
	else if (c == 'C')
		ft_image_push(data, data->collectible, x, y);
	else if (c == 'B')
		ft_image_push(data, data->fly, x, y);
	else
		ft_assign_images_to_map_bonus(data, y, x, c);
}

// Function to go through the map and scoot for
// changes. Sends then the results to interpret

void	ft_parse_map(t_huge *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->y_axis)
	{
		x = 0;
		while (x < data->x_axis)
		{
			ft_assign_images_to_map(data, y, x, data->map[y][x]);
			x++;
		}
		y++;
	}
}

// Assigns images to verables

void	ft_assign_textures_to_images(t_huge *data)
{
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE, &data->img_width, &data->img_height);
	data->grass = mlx_xpm_file_to_image(data->mlx,
			GRASS, &data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &data->img_width, &data->img_height);
	data->hero_up = mlx_xpm_file_to_image(data->mlx,
			HERO_UP, &data->img_width, &data->img_height);
	data->hero_down = mlx_xpm_file_to_image(data->mlx,
			HERO_DOWN, &data->img_width, &data->img_height);
	data->hero_left = mlx_xpm_file_to_image(data->mlx,
			HERO_LEFT, &data->img_width, &data->img_height);
	data->hero_right = mlx_xpm_file_to_image(data->mlx,
			HERO_RIGHT, &data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &data->img_width, &data->img_height);
	data->fly = mlx_xpm_file_to_image(data->mlx,
			FLY1, &data->img_width, &data->img_height);
	ft_assign_textures_to_images_bonus(data);
	data->swtch = 0;
}

// Sets up the mlx loop and different variables that
// We are going to use down the road.

void	ft_mlx_map_init(t_huge *data)
{
	int	x;

	x = data->map_size_x;
	data->count = 0;
	data->loop = 0;
	data->spr = 0;
	data->f_coord_x = 0;
	data->f_coord_y = 0;
	data->p_coord_x = 0;
	data->p_coord_y = 0;
	if (data->map_size_x < 4 * SIZE)
		data->map_size_x = 4 * SIZE;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map_size_x, data->map_size_y + SIZE, "so_long");
	ft_assign_textures_to_images(data);
	ft_status_bar(data);
	ft_arrange_status_bar(data, x);
	ft_status_bar_init(data);
	ft_parse_map(data);
	mlx_hook(data->mlx_win, 17, 0L, &ft_free_game, data);
	mlx_hook(data->mlx_win, 02, 1L << 0, ft_movement_init, (void *)data);
	mlx_loop_hook(data->mlx, ft_sprite, (void *)data);
	mlx_loop(data->mlx);
}
