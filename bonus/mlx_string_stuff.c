/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:41:59 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 21:00:47 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Prints the numbers in the game window rather than
// in the shell. Took liberty of adding collectibles

void	ft_string_to_map(t_huge *data)
{
	char	*steps;
	char	*coll;

	steps = ft_itoa(data->count);
	coll = ft_itoa(data->c);
	ft_status_bar(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->st,
		SIZE, data->map_size_y);
	mlx_string_put(data->mlx, data->mlx_win, SIZE + 10,
		data->map_size_y + SIZE / 2 - 10, 0xffffff, steps);
	mlx_string_put(data->mlx, data->mlx_win, 3 * SIZE + 10,
		data->map_size_y + SIZE / 2 - 10, 0xffffff, coll);
	free(steps);
	free(coll);
}

// Function for the footer of the game.
// Static int just there to avoid freeing the first loop around

void	ft_status_bar(t_huge *data)
{
	int			i;
	static int	check = 0;

	if (check != 0)
		ft_keep_freeing_game(data);
	i = 0;
	data->st = mlx_xpm_file_to_image(data->mlx,
			STATUS, &data->img_width, &data->img_height);
	data->stf = mlx_xpm_file_to_image(data->mlx,
			STATUS_FOOT, &data->img_width, &data->img_height);
	data->stc = mlx_xpm_file_to_image(data->mlx,
			STATUS_COIN, &data->img_width, &data->img_height);
	while (i < data->map_size_x)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->st, i, data->map_size_y);
		i += SIZE;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->stf, 0, data->map_size_y);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->stc, 2 * SIZE, data->map_size_y);
	check++;
}

// displays the digits before the first move of the hero

void	ft_status_bar_init(t_huge *data)
{
	char	*coll;
	char	*steps;

	coll = ft_itoa(data->c);
	steps = ft_itoa(data->count);
	mlx_string_put(data->mlx, data->mlx_win, SIZE + 10,
		data->map_size_y + SIZE / 2 - 10, 0xffffff, steps);
	mlx_string_put(data->mlx, data->mlx_win, 3 * SIZE + 10,
		data->map_size_y + SIZE / 2 - 10, 0xffffff, coll);
	free(coll);
	free(steps);
}

// function to make sure the window size is big enough
// for the footer. if not, puts textures accordingly
// to make it look good.

void	ft_arrange_status_bar(t_huge *data, int x)
{
	int	i;

	i = 0;
	if (x < data->map_size_x)
	{
		while (i < data->map_size_y)
		{
			mlx_put_image_to_window(data->mlx,
				data->mlx_win, data->st, 3 * SIZE, i);
			i += 32;
		}
	}
	else
		return ;
}
