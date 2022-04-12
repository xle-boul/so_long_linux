/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:45:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 15:44:54 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_char(char c)
{
	int	i;

	i = 0;
	while (MAP_CHARS[i])
	{
		if (MAP_CHARS[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (-1);
}

void	ft_check_map_standards(t_huge *data)
{
	int		i;
	int		j;

	i = 0;
	data->x_axis = ft_strlen(data->map[i]);
	if (data->y_axis < 2)
		ft_error_and_free(2, data);
	while (i < data->y_axis)
	{
		if ((int)ft_strlen(data->map[i]) != data->x_axis)
			ft_error_and_free(4, data);
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (ft_check_char(data->map[i][j]) == -1)
				ft_error_and_free(7, data);
			j++;
		}
		i++;
	}
	data->map_size_x = data->x_axis * SIZE;
	data->map_size_y = data->y_axis * SIZE;
	return ;
}

void	ft_check_map_closed(t_huge *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_axis)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[0][j] != '1')
				ft_error_and_free(5, data);
			if (data->map[i][0] != '1')
				ft_error_and_free(5, data);
			if (data->map[i][(int)ft_strlen(data->map[i]) - 1] != '1')
				ft_error_and_free(5, data);
			if (data->map[data->y_axis - 1][j] != '1')
				ft_error_and_free(5, data);
			j++;
		}
		i++;
	}
}

void	ft_precheck_map_obstacles(t_huge *data)
{
	data->c = 0;
	data->e = 0;
	data->i = 0;
	data->p = 0;
	data->zero = 0;
	ft_check_map_obstacles(data);
}

void	ft_check_map_obstacles(t_huge *data)
{
	while (data->i < data->y_axis)
	{
		data->j = 0;
		while (data->map[data->i][data->j] != '\0')
		{
			if (data->map[data->i][data->j] == 'C')
				data->c++;
			if (data->map[data->i][data->j] == 'E')
				data->e++;
			if (data->map[data->i][data->j] == 'P')
				data->p++;
			if (data->map[data->i][data->j] == '0')
				data->zero++;
			data->j++;
		}
		data->i++;
	}
	if (data->e == 0 || data->p != 1 || data->c == 0)
		ft_error_and_free(6, data);
}
