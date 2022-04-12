/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:25:08 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 21:01:07 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_huge *data)
{
	if (data->map[data->p_coord_y - 1][data->p_coord_x] != '1')
	{
		if (data->map[data->p_coord_y - 1][data->p_coord_x] == 'E'
			&& data->c != 0)
			return ;
		if (data->map[data->p_coord_y - 1][data->p_coord_x] == 'C')
			data->c--;
		data->count++;
		ft_printf("moves: %d\n", data->count);
		data->map[data->p_coord_y][data->p_coord_x] = '0';
		if (data->map[data->p_coord_y - 1][data->p_coord_x] == 'E'
			&& data->c == 0)
		{
			ft_printf("GG, %d moves! Sure you could do better\n", data->count);
			ft_free_game(data);
			return ;
		}
		data->map[data->p_coord_y - 1][data->p_coord_x] = 'P';
	}
	data->swtch = 1;
	ft_parse_map(data);
}

void	ft_move_down(t_huge *data)
{
	if (data->map[data->p_coord_y + 1][data->p_coord_x] != '1')
	{
		if (data->map[data->p_coord_y + 1][data->p_coord_x] == 'E'
			&& data->c != 0)
			return ;
		if (data->map[data->p_coord_y + 1][data->p_coord_x] == 'C')
				data->c--;
		data->count++;
		ft_printf("moves: %d\n", data->count);
		data->map[data->p_coord_y][data->p_coord_x] = '0';
		if (data->map[data->p_coord_y + 1][data->p_coord_x] == 'E'
			&& data->c == 0)
		{
			ft_printf("GG, %d moves! Sure you could do better\n", data->count);
			ft_free_game(data);
			return ;
		}
		data->map[data->p_coord_y + 1][data->p_coord_x] = 'P';
	}
	data->swtch = 0;
	ft_parse_map(data);
}

void	ft_move_left(t_huge *data)
{
	if (data->map[data->p_coord_y][data->p_coord_x - 1] != '1')
	{
		if ((data->map[data->p_coord_y][data->p_coord_x - 1] == 'E'
			&& data->c != 0))
			return ;
		if (data->map[data->p_coord_y][data->p_coord_x - 1] == 'C')
			data->c--;
		data->count++;
		ft_printf("moves: %d\n", data->count);
		data->map[data->p_coord_y][data->p_coord_x] = '0';
		if (data->map[data->p_coord_y][data->p_coord_x - 1] == 'E'
			&& data->c == 0)
		{
			ft_printf("GG, %d moves! Sure you could do better\n", data->count);
			ft_free_game(data);
			return ;
		}
		data->map[data->p_coord_y][data->p_coord_x - 1] = 'P';
	}
	data->swtch = 2;
	ft_parse_map(data);
}

void	ft_move_right(t_huge *data)
{
	if (data->map[data->p_coord_y][data->p_coord_x + 1] != '1')
	{
		if (data->map[data->p_coord_y][data->p_coord_x + 1] == 'E'
			&& data->c != 0)
			return ;
		if (data->map[data->p_coord_y][data->p_coord_x + 1] == 'C')
			data->c--;
		data->count++;
		ft_printf("moves: %d\n", data->count);
		data->map[data->p_coord_y][data->p_coord_x] = '0';
		if (data->map[data->p_coord_y][data->p_coord_x + 1] == 'E'
			&& data->c == 0)
		{
			ft_printf("GG, %d moves! Sure you could do better\n", data->count);
			ft_free_game(data);
			return ;
		}
		data->map[data->p_coord_y][data->p_coord_x + 1] = 'P';
	}
	data->swtch = 3;
	ft_parse_map(data);
}

// Hero movement based on key press. Send to the proper
// function. Also triggers the display of numbers on
// sceen.

int	ft_movement_init(int key, t_huge *data)
{
	if (key == 65307)
		ft_free_game(data);
	else if (key == 'w' || key == 65362)
		ft_move_up(data);
	else if (key == 'a' || key == 65361)
		ft_move_left(data);
	else if (key == 's' || key == 65364)
		ft_move_down(data);
	else if (key == 'd' || key == 65363)
		ft_move_right(data);
	else
		return (0);
	return (0);
}
