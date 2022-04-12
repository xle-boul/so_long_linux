/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:54:33 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 15:57:40 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à collecter (C pour collectible),
// E pour une sortie (E pour exit),
// P pour la position de départ du personnage.

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	*head;
	t_huge	data;

	head = NULL;
	data.file = av[1];
	if (ac != 2)
		ft_error_handler(3);
	if (ft_strnstr(data.file, ".ber", ft_strlen(data.file)) == NULL)
		ft_error_handler(3);
	head = ft_map_init(&data, head);
	ft_list_to_2d_array(head, &data);
	ft_mlx_map_init(&data);
	return (0);
}
