/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:13:41 by xle-boul          #+#    #+#             */
/*   Updated: 2022/03/19 08:44:48 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_handler(int error)
{
	if (error == 0)
		ft_printf("Error\nmalloc");
	if (error == 1)
		ft_printf("Error\nreading map");
	if (error == 2)
		ft_printf("Error\nmap format incorrect");
	if (error == 3)
		ft_printf("Error\nargument incorrect, please use a .ber file");
	if (error == 4)
		ft_printf("Error\nmap isn't a rectangle");
	if (error == 5)
		ft_printf("Error\nmap isn't closed");
	if (error == 6)
		ft_printf("Error\n1 start pos and at least 1 exit and 1 collectible");
	if (error == 7)
		ft_printf("Error\nonly 'E', 'P', 'C', '0' and '1' work for a map");
	exit(EXIT_FAILURE);
}

void	ft_error_and_free(int error, t_huge *data)
{
	if (error == 0)
		ft_printf("Error\nmalloc");
	if (error == 1)
		ft_printf("Error\nreading map");
	if (error == 2)
		ft_printf("Error\nmap format incorrect");
	if (error == 3)
		ft_printf("Error\nargument incorrect, please use a .ber file");
	if (error == 4)
		ft_printf("Error\nmap isn't a rectangle");
	if (error == 5)
		ft_printf("Error\nmap isn't closed");
	if (error == 6)
		ft_printf("Error\n1 start pos and at least 1 exit and 1 collectible");
	if (error == 7)
		ft_printf("Error\nonly 'E', 'P', 'C', '0' and '1' work for a map");
	if (error == 8)
		ft_printf("Error\nplease add at least a foe with a 'F' in the map");
	ft_free_map(data);
	exit(EXIT_FAILURE);
}
