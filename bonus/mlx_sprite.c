/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:05:58 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 13:16:43 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Static foes animation

void	ft_animate_sprite(t_huge *data)
{
	if (data->spr != 6)
		mlx_destroy_image(data->mlx, data->fly);
	if (data->spr == 0)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY1, &data->img_width, &data->img_height);
	if (data->spr == 1)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY2, &data->img_width, &data->img_height);
	if (data->spr == 2)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY3, &data->img_width, &data->img_height);
	if (data->spr == 3)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY4, &data->img_width, &data->img_height);
	if (data->spr == 4)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY5, &data->img_width, &data->img_height);
	if (data->spr == 5)
		data->fly = mlx_xpm_file_to_image(data->mlx,
				FLY6, &data->img_width, &data->img_height);
	if (data->spr == 6)
		data->spr = 0;
	data->spr++;
	ft_parse_map(data);
}

// Initiate big boss' movement and setup sprite animation
// for static foes -> animation timed over repeated loop

int	ft_sprite(t_huge *data)
{
	int		sec;
	time_t	seconds;

	time(&seconds);
	sec = seconds;
	ft_enemy_movement_init(data, sec);
	if (data->loop < 300)
	{
		data->loop++;
		return (0);
	}
	ft_animate_sprite(data);
	data->loop = 0;
	return (0);
}
