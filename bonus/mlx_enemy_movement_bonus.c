/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_movement_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:42:54 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 21:25:34 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Allows to print the correct background behind the foe.
// If he steps on coins, they show behind him

int	ft_check_where_from(t_huge *data)
{
	if (data->map[data->f_coord_y][data->f_coord_x] == 'S')
		return (0);
	else if (data->map[data->f_coord_y][data->f_coord_x] == 'F')
		return (1);
	return (-1);
}

void	ft_enemy_move_up(t_huge *data)
{
	if (data->map[data->f_coord_y - 1][data->f_coord_x] == '0')
	{
		data->swtch_foe = 1;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y - 1][data->f_coord_x] = 'F';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y - 1][data->f_coord_x] == 'C')
	{
		data->swtch_foe = 5;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y - 1][data->f_coord_x] = 'S';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y - 1][data->f_coord_x] == 'P')
		ft_you_lose(data, data->f_coord_y - 1, data->f_coord_x);
	else
		ft_enemy_move_down(data);
}

void	ft_enemy_move_down(t_huge *data)
{
	if (data->map[data->f_coord_y + 1][data->f_coord_x] == '0')
	{
		data->swtch_foe = 0;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y + 1][data->f_coord_x] = 'F';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y + 1][data->f_coord_x] == 'C')
	{
		data->swtch_foe = 4;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y + 1][data->f_coord_x] = 'S';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y + 1][data->f_coord_x] == '0')
		ft_you_lose(data, data->f_coord_y + 1, data->f_coord_x);
	else
		ft_enemy_move_left(data);
}

void	ft_enemy_move_left(t_huge *data)
{
	if (data->map[data->f_coord_y][data->f_coord_x - 1] == '0')
	{
		data->swtch_foe = 2;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x - 1] = 'F';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y][data->f_coord_x - 1] == 'C')
	{
		data->swtch_foe = 6;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x - 1] = 'S';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y][data->f_coord_x - 1] == 'P')
		ft_you_lose(data, data->f_coord_y, data->f_coord_x - 1);
	else
		ft_enemy_move_right(data);
}

void	ft_enemy_move_right(t_huge *data)
{
	if (data->map[data->f_coord_y][data->f_coord_x + 1] == '0')
	{
		data->swtch_foe = 3;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x + 1] = 'F';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y][data->f_coord_x + 1] == 'C')
	{
		data->swtch_foe = 7;
		if (ft_check_where_from(data) == 0)
			data->map[data->f_coord_y][data->f_coord_x] = 'C';
		if (ft_check_where_from(data) == 1)
			data->map[data->f_coord_y][data->f_coord_x] = '0';
		data->map[data->f_coord_y][data->f_coord_x + 1] = 'S';
		ft_parse_map(data);
	}
	else if (data->map[data->f_coord_y][data->f_coord_x + 1] == 'P')
		ft_you_lose(data, data->f_coord_y, data->f_coord_x + 1);
	else
		ft_enemy_move_up(data);
}
