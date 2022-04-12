/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:19:50 by xle-boul          #+#    #+#             */
/*   Updated: 2022/04/12 20:04:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>
# include "../ft_printf/header/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "get_next_line.h"

// defined some variables for easier reading

# define MAP_CHARS "01CPE"
# define SIZE 32
# define HERO_UP "textures/hero/hero_back.xpm"
# define HERO_DOWN "textures/hero/hero_front.xpm"
# define HERO_LEFT "textures/hero/hero_left.xpm"
# define HERO_RIGHT "textures/hero/hero_right.xpm"
# define COLLECTIBLE "textures/collectible/collectible.xpm"
# define GRASS "textures/grass/grass_tile.xpm"
# define WALL "textures/wall/wall.xpm"
# define EXIT "textures/exit/exit.xpm"

// Struct to assign ligns of the map to a chained list

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

// Struct to handle the rest of the stuff

typedef struct s_huge
{
	char		*file;
	int			fd;
	char		*line;
	int			x_axis;
	int			y_axis;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	char		*relative_path;
	void		*hero_down;
	void		*hero_up;
	void		*hero_left;
	void		*hero_right;
	void		*vader_down;
	void		*vader_up;
	void		*vader_left;
	void		*vader_right;
	void		*vader_down_c;
	void		*vader_up_c;
	void		*vader_left_c;
	void		*vader_right_c;
	int			swtch;
	int			swtch_foe;
	void		*grass;
	void		*wall;
	void		*collectible;
	void		*exit;
	int			map_size_x;
	int			map_size_y;
	int			height;
	int			width;
	int			count;
	int			p_coord_x;
	int			p_coord_y;
	int			f_coord_x;
	int			f_coord_y;
	int			e;
	int			c;
	int			i;
	int			j;
	int			f;
	int			zero;
	int			p;
	int			loop;
	void		*fly;
	int			spr;
	void		*st;
	void		*stf;
	void		*stc;
}				t_huge;

// Chained listed map stuff

char	*ft_strjoin_gnl(char *patch, char *buf);
t_map	*ft_create_new_node(char	*line);
void	ft_add_at_tail(t_map **head, t_map *new);

// Conversion to 2d array and check if map is compliant

void	ft_list_to_2d_array(t_map *head, t_huge *data);
t_map	*ft_map_init(t_huge *data, t_map *head);
void	ft_check_map_standards(t_huge *data);
void	ft_check_map_closed(t_huge *data);
void	ft_precheck_map_obstacles(t_huge *data);
void	ft_check_map_obstacles(t_huge *data);

// Error handling

void	ft_error_handler(int error);
void	ft_error_and_free(int error, t_huge *data);

// Freeing malloc'd stuff

void	ft_free_list(t_map *head);
void	ft_free_map(t_huge *data);
int		ft_free_game(t_huge *data);

// MLX specific stuff

void	ft_mlx_map_init(t_huge *data);
int		ft_movement_init(int key, t_huge *data);
void	ft_parse_map(t_huge *data);

#endif