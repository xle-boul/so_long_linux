/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:19:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 20:38:24 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <time.h>
# include "so_long.h"

# define VADER_UP "textures/vader/vader_back.xpm"
# define VADER_DOWN "textures/vader/vader_front.xpm"
# define VADER_LEFT "textures/vader/vader_left.xpm"
# define VADER_RIGHT "textures/vader/vader_right.xpm"
# define VADER_UP_C "textures/vader/vader_back_c.xpm"
# define VADER_DOWN_C "textures/vader/vader_front_c.xpm"
# define VADER_LEFT_C "textures/vader/vader_left_c.xpm"
# define VADER_RIGHT_C "textures/vader/vader_right_c.xpm"

# define FLY1 "textures/fly/fly01.xpm"
# define FLY2 "textures/fly/fly02.xpm"
# define FLY3 "textures/fly/fly03.xpm"
# define FLY4 "textures/fly/fly04.xpm"
# define FLY5 "textures/fly/fly05.xpm"
# define FLY6 "textures/fly/fly06.xpm"

# define FOOT "textures/foot/foot.xpm"
# define STATUS "textures/status/status.xpm"
# define STATUS_FOOT "textures/status/status_foot.xpm"
# define STATUS_COIN "textures/status/status_coin.xpm"

# define MAP_CHARS_BONUS "01ECPFB"

// Initiate map with textures

void	ft_assign_textures_to_images_bonus(t_huge *data);
void	ft_choose_which_foe(t_huge *data, int x, int y);
void	ft_assign_images_to_map_bonus(t_huge *data, int y, int x, char c);
void	ft_choose_which_hero(t_huge *data, int x, int y);
void	ft_assign_textures_to_images(t_huge *data);
void	ft_image_push(t_huge *data, void *texture, int x, int y);

// Enemy movement

void	ft_enemy_move_up(t_huge *data);
void	ft_enemy_move_down(t_huge *data);
void	ft_enemy_move_left(t_huge *data);
void	ft_enemy_move_right(t_huge *data);
void	ft_enemy_movement_init(t_huge *data, int sec);
int		ft_check_where_from(t_huge *data);

// Hero movement

void	ft_move_right(t_huge *data);
void	ft_move_left(t_huge *data);
void	ft_move_down(t_huge *data);
void	ft_move_up(t_huge *data);

// Game over

void	ft_game_over(t_huge *data, char c);
void	ft_you_lose(t_huge *data, int y, int x);
void	ft_keep_freeing_game(t_huge *data);

// Sprites

int		ft_sprite(t_huge *data);
void	ft_animate_sprite(t_huge *data);

// String

void	ft_status_bar_init(t_huge *data);
void	ft_string_to_map(t_huge *data);
void	ft_status_bar(t_huge *data);
void	ft_arrange_status_bar(t_huge *data, int x);

#endif