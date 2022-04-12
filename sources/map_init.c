/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:31:58 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 15:43:05 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Creates a new node of the list containing a line of the map

t_map	*ft_create_new_node(char	*line)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		ft_error_handler(0);
	node->line = ft_strdup(line);
	if (!node->line)
		ft_error_handler(0);
	node->next = NULL;
	return (node);
}

// Takes each node of the list and then copies it to an array
// into a 2d array. Makes it easier to work with thereafter.
// Also sends the 2d array to various checks to make sure the map
// is compliant.

void	ft_list_to_2d_array(t_map *head, t_huge *data)
{
	t_map	*tmp;
	int		i;

	i = 0;
	data->map = malloc(sizeof(char *) * data->y_axis);
	if (!data->map)
	{
		ft_free_list(head);
		ft_error_handler(0);
	}
	tmp = head;
	while (tmp != NULL)
	{
		data->map[i] = ft_strdup(tmp->line);
		tmp = tmp->next;
		i++;
	}
	ft_free_list(head);
	ft_check_map_standards(data);
	ft_check_map_closed(data);
	ft_precheck_map_obstacles(data);
}

// Copies a new node of a list to its head if the latter wasn't assigned.
// Else, it goes to the end of the list and adds the new node after it.

void	ft_add_at_tail(t_map **head, t_map *new)
{
	t_map	*tmp;

	if (!(*head))
	{
		*head = new;
		return ;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// Creates a chained list from each line that get_next_line pulls.

t_map	*ft_map_init(t_huge *data, t_map *head)
{
	t_map	*new;

	data->y_axis = 0;
	head = NULL;
	data->fd = open(data->file, O_RDONLY);
	if (data->fd == -1)
		ft_error_handler(1);
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
		{
			free (data->line);
			break ;
		}
		new = ft_create_new_node(data->line);
		ft_add_at_tail(&head, new);
		data->y_axis++;
		free (data->line);
	}
	if (data->y_axis == 0)
		ft_error_handler(1);
	close (data->fd);
	return (head);
}
