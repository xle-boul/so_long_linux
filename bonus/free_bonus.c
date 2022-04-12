/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:56:05 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 20:19:43 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Dual use: free at the end of the game and free the
// footer in between each call for the string input.

void	ft_keep_freeing_game(t_huge *data)
{
	mlx_destroy_image(data->mlx, data->st);
	mlx_destroy_image(data->mlx, data->stf);
	mlx_destroy_image(data->mlx, data->stc);
}

// Free mlx stuff allocated

int	ft_free_game(t_huge *data)
{
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->hero_down);
	mlx_destroy_image(data->mlx, data->hero_up);
	mlx_destroy_image(data->mlx, data->hero_left);
	mlx_destroy_image(data->mlx, data->hero_right);
	mlx_destroy_image(data->mlx, data->vader_down);
	mlx_destroy_image(data->mlx, data->vader_up);
	mlx_destroy_image(data->mlx, data->vader_left);
	mlx_destroy_image(data->mlx, data->vader_right);
	mlx_destroy_image(data->mlx, data->vader_down_c);
	mlx_destroy_image(data->mlx, data->vader_up_c);
	mlx_destroy_image(data->mlx, data->vader_left_c);
	mlx_destroy_image(data->mlx, data->vader_right_c);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->grass);
	mlx_destroy_image(data->mlx, data->fly);
	ft_keep_freeing_game(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data);
	ft_printf("Program performed a clean exit.\n");
	exit(EXIT_SUCCESS);
}

void	ft_game_over(t_huge *data, char c)
{
	if (data->f_coord_x == data->p_coord_x
		&& data->f_coord_y == data->p_coord_y)
	{
		ft_printf("You lost... To Darth Vader, Predictable! NOOB!\n");
		ft_free_game(data);
	}
	else if (c == 'E')
	{
		ft_printf("GG, %d moves! Sure you could do better\n", data->count);
		ft_free_game(data);
		return ;
	}
}

// Handles the case you collide with mobs or foe.

void	ft_you_lose(t_huge *data, int y, int x)
{
	int	i;
	int	j;

	i = data->f_coord_x;
	j = data->f_coord_y;
	if (y == -1 && x == -1)
	{
		ft_printf("You lost... To a bat... Really?! NOOB!\n");
		ft_free_game(data);
	}
	if (ft_check_where_from(data) == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collectible, i * SIZE, j * SIZE);
	if (ft_check_where_from(data) == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->grass, i * SIZE, j * SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->vader_down, x * SIZE, y * SIZE);
	ft_printf("You lost... To Darth Vader, Predictable! NOOB!\n");
	ft_free_game(data);
}
