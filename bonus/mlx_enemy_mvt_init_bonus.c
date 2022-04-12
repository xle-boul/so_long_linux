/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_mvt_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:41 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 16:46:51 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_enemy_check(t_huge *data)
{
	if (data->map[data->f_coord_y + 1][data->f_coord_x] == '1'
		&& data->map[data->f_coord_y - 1][data->f_coord_x] == '1'
		&& data->map[data->f_coord_y][data->f_coord_x + 1] == '1'
		&& data->map[data->f_coord_y][data->f_coord_x - 1] == '1')
		return (-1);
	return (0);
}

// Pseudo random number generator using the rand() function
// associated with %4 of the seconds passed

int	ft_random_number_generator(void)
{
	int		i;
	time_t	seconds;

	time(&seconds);
	i = (rand() + seconds) % 4;
	return (i);
}

// Initiates the foe's movements. Receives the seconds elapsed
// and checks if the previous matches. If it doesn't, the feo
// moves. This allows for a movement every second.

void	ft_enemy_movement_init(t_huge *data, int sec)
{
	int			mvt;
	static int	checker;

	if (ft_enemy_check(data) == -1)
		return ;
	mvt = ft_random_number_generator();
	if (sec != checker && ft_enemy_check(data) == 0)
	{
		if (mvt == 0)
			ft_enemy_move_up(data);
		else if (mvt == 1)
			ft_enemy_move_down(data);
		else if (mvt == 2)
			ft_enemy_move_left(data);
		else if (mvt == 3)
			ft_enemy_move_right(data);
	}
	checker = sec;
}
