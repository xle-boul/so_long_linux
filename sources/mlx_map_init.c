/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:50:57 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 21:32:37 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Selects the right images according to the direction
// of our hero

void	ft_choose_which_hero(t_huge *data, int x, int y)
{
	if (data->swtch == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hero_down, x * SIZE, y * SIZE);
	if (data->swtch == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hero_up, x * SIZE, y * SIZE);
	if (data->swtch == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hero_left, x * SIZE, y * SIZE);
	if (data->swtch == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hero_right, x * SIZE, y * SIZE);
}

// Prints the proper images according to the char scouted

void	ft_assign_images_to_map(t_huge *data, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall, x * SIZE, y * SIZE);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass, x * SIZE, y * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->exit, x * SIZE, y * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collectible, x * SIZE, y * SIZE);
	else if (c == 'P')
	{
		ft_choose_which_hero(data, x, y);
		data->p_coord_x = x;
		data->p_coord_y = y;
	}
}

// Function to go through the map and scoot for
// changes. Sends then the results to interpret

void	ft_parse_map(t_huge *data)
{
	int	y;
	int	x;

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

// Sets up the mlx loop and different variables that
// We are going to use down the road.

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
	data->swtch = 0;
}

void	ft_mlx_map_init(t_huge *data)
{
	data->count = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			data->map_size_x, data->map_size_y, "so_long");
	ft_assign_textures_to_images(data);
	ft_parse_map(data);
	mlx_hook(data->mlx_win, 17, 0L, &ft_free_game, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &ft_movement_init, data);
	mlx_loop(data->mlx);
}
