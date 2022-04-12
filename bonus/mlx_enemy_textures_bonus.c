/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:47:09 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 21:21:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Simple function to put images to window, just to gain lines

void	ft_image_push(t_huge *data, void *texture, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		texture, x * SIZE, y * SIZE);
}

// Selects the right images according to the direction
// of our hero

void	ft_choose_which_hero(t_huge *data, int x, int y)
{
	if (data->swtch == 0)
		ft_image_push(data, data->hero_down, x, y);
	if (data->swtch == 1)
		ft_image_push(data, data->hero_up, x, y);
	if (data->swtch == 2)
		ft_image_push(data, data->hero_left, x, y);
	if (data->swtch == 3)
		ft_image_push(data, data->hero_right, x, y);
}

// Assigns images to variables. This time around for the foe

void	ft_assign_textures_to_images_bonus(t_huge *data)
{
	data->vader_up = mlx_xpm_file_to_image(data->mlx,
			VADER_UP, &data->img_width, &data->img_height);
	data->vader_down = mlx_xpm_file_to_image(data->mlx,
			VADER_DOWN, &data->img_width, &data->img_height);
	data->vader_left = mlx_xpm_file_to_image(data->mlx,
			VADER_LEFT, &data->img_width, &data->img_height);
	data->vader_right = mlx_xpm_file_to_image(data->mlx,
			VADER_RIGHT, &data->img_width, &data->img_height);
	data->vader_up_c = mlx_xpm_file_to_image(data->mlx,
			VADER_UP_C, &data->img_width, &data->img_height);
	data->vader_down_c = mlx_xpm_file_to_image(data->mlx,
			VADER_DOWN_C, &data->img_width, &data->img_height);
	data->vader_left_c = mlx_xpm_file_to_image(data->mlx,
			VADER_LEFT_C, &data->img_width, &data->img_height);
	data->vader_right_c = mlx_xpm_file_to_image(data->mlx,
			VADER_RIGHT_C, &data->img_width, &data->img_height);
	data->swtch_foe = 0;
}

// Choses the right image according to the direction of the foe

void	ft_choose_which_foe(t_huge *data, int x, int y)
{
	if (data->swtch_foe == 0)
		ft_image_push(data, data->vader_down, x, y);
	if (data->swtch_foe == 1)
		ft_image_push(data, data->vader_up, x, y);
	if (data->swtch_foe == 2)
		ft_image_push(data, data->vader_left, x, y);
	if (data->swtch_foe == 3)
		ft_image_push(data, data->vader_right, x, y);
	if (data->swtch_foe == 4)
		ft_image_push(data, data->vader_down_c, x, y);
	if (data->swtch_foe == 5)
		ft_image_push(data, data->vader_up_c, x, y);
	if (data->swtch_foe == 6)
		ft_image_push(data, data->vader_left_c, x, y);
	if (data->swtch_foe == 7)
		ft_image_push(data, data->vader_right_c, x, y);
}
