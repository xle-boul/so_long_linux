/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_base_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:29:15 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/17 21:29:49 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// Speaks for itself

void	ft_free_list(t_map *head)
{
	t_map	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free (head->line);
		free (head);
		head = tmp;
	}
	head = NULL;
}

// This one too

void	ft_free_map(t_huge *data)
{
	int	i;

	i = data->y_axis - 1;
	while (i >= 0)
	{
		free (data->map[i]);
		i--;
	}
	free (data->map);
}
