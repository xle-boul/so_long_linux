/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:39:49 by xle-boul          #+#    #+#             */
/*   Updated: 2021/11/23 16:27:42 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

void	ft_printf_c_basic(t_char c, t_tot *tot)
{
	ft_putchar_fd_print(c.c, 1, tot);
}

void	ft_c_setup(t_flags flags, va_list args, t_tot *tot)
{
	t_char	c;

	c.i = 0;
	if (flags.param == '%')
	{
		ft_putchar_fd_print('%', 1, tot);
		return ;
	}
	c.c = va_arg(args, int);
	ft_printf_c_basic(c, tot);
}
