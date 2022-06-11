/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:05:53 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 15:39:44 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include  <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "gnl/get_next_line.h"

# include <time.h>

# include "parser/libft/libft.h"
# define K_ESC 53
# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2
# define K_LEFT_ARROW 123
# define K_RIGHT_ARROW 124

typedef struct s_textures
{
	char	*path;
}			t_textures;

typedef struct s_player
{
	double			plane_x;
	double			plane_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				lrotate;
	int				rrotate;
	int				pos;
	char			dir;
	char			charak;
}					t_player;

typedef struct s_map
{
	int				h;
	int				w;
	int				x;
	int				y;
	int				step_x;
	int				step_y;
	char			**map;
	int				map_width;
	int				map_height;
}					t_map;

typedef struct s_screen
{
	int				w;
	int				h;
}					t_screen;

typedef struct s_all
{
	t_player		plr;
	t_map			map;
	t_screen		screen;
	t_textures		tx[4];
	char			**maplines;
	int				resolution_ok;
	int				tx_ok[3];
	unsigned int	fcolor;
	int				f_clr[3];
	int				f_clr_0;
	int				f_clr_1;
	int				f_clr_2;
	int				f_ok;
	unsigned int	ccolor;
	int				c_clr[3];
	int				c_clr_0;
	int				c_clr_1;
	int				c_clr_2;
	int				c_ok;
	char			*str;
	char			**tmp;
	int				j;
}					t_all;
/*__________________________________________________________*/
typedef struct s_data
{
	int				x;
	int				y;
	char			content;
	struct s_data	*next;
}				t_data;

typedef struct s_position
{
	float		x_pos;
	float		y_pos;
	float		dx_pos;
	float		dy_pos;
	float		angle_pos;
}				t_position;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_ray
{
	float		ra;
	float		rx_h;
	float		ry_h;
	float		rx_v;
	float		ry_v;
	float		x0;
	float		y0;
	float		rx;
	float		ry;
	float		distance;
	int			hor_or_ver;
	int			first_pixel;
}				t_ray;

typedef struct s_list {
	float		Pi;
	float		Pi_mul_15;
	float		Pi_mul_2;
	float		Pi_div_2;
	float		Pi_div_3600;
	int			width;
	int			height;
	int			scr_resol_x;
	int			scr_resol_y;
	int			pixel_per_stripe;
	int			position_numb;
	int			is_map_checked;
	void		*mlx;
	void		*window;

	int			cur_pix_to_push;
	t_image		*texture;
	t_image		push;
	t_image		stripe;
	t_image		coef_stripe;
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	t_data		*map;
	t_ray		ray;
	t_position	new_pos;
	t_position	old_pos;
	t_all		*a;
}				t_list;

void				ft_copy_position(t_list *base);
void				ft_return_position(t_list *base);
int					ft_check_around(t_list *base);
int					ft_close(t_list *base);
int					key_hook(int keycode, t_list *base);
int					ft_do_move(t_list *base);
int					ft_display_move(t_list *base);

void				add_to_background(t_list *base, int x, int y);
void				ft_prepare_for_stripe(t_list *base);
int					ft_take_stripe(t_list *base,
						int first_pixel, int pixel_per_stripe);
void				ft_add_stripe(t_list *base, float coef);
int					ft_create_background(t_list *base, t_all *a);
//int				ft_create_background(t_list *base);
int					ft_built_view(t_list *base, t_all *a);/**/
//int				ft_built_view(t_list *base);
int					ft_load_images(t_list *base, t_all *a);
//int				ft_load_images(t_list *base);

char				ft_check_content(t_list *base, float x, float y);
int					ft_check_horizontal(t_list *base);
int					ft_check_vertical(t_list *base);
int					ft_check_crossing(t_list *base);

int					ft_create_trgb(int transparency,
						int red, int green, int blue);
t_data				*ft_lstnew(int x, int y, char content);
t_data				*ft_lstlast(t_data *lst);
//t_data			*ft_create_map(int fd, t_list *base);
t_data				*ft_create_map(int fd, t_list *base, char **mape, t_all *a);
void				ft_lstadd_back(t_data **lst, t_data *new);
void				ft_putchar(char c);
void				ft_putstr(char *s);
char				*ft_itoa(int n);
char				ft_is_it_allowed(t_list *base);
int					ft_check_map(t_data *lst, t_list *base);
int					ft_images_to_map(t_data *lst, t_list *base);
int					ft_find_position(t_list *base);
int					ft_find_size_map(t_list *base);
int					ft_map_error(t_list *base);
int					ft_check_extension(char *string);
int					ft_lstfree(t_data **lst);
int					ft_initialize_base(int argc, t_list *base);
int					ft_initialize_mlx(t_list *base);

/*_____________cchel________________*/
int					rft_utils_2(t_all *a);
void				create_and_check_map(t_all *a, char **maplines);
void				parse_cub(t_all *a, char *map_file);
char				**get_maplines(char **lines, int fd, t_all *a, int i);
void				ft_error(char *str, t_all *a);
void				init_config(t_all *a);
void				init_screen_size(t_all *a);
int					init_player(int x, int y, char dir, t_all *a);
void				init_map(t_all *a, char **cropped_lines, int i);
void				rft_get_malloc(t_all *a);
void				rft_get_malloc_i(t_all *a, int i);
void				check_player(t_all *a);
void				check_cropped_map_line(char *str, t_all *a);
void				check_map_horizontally(t_all *a);
void				check_map_vertically(t_all *a);
void				player_direction(char dir, t_all *a, int x, int y);
int					numlen(char *str);
unsigned int		get_color(char *str, t_all *a, char c);
int					config_checker(t_all *a, char *str);
unsigned int		rft_get_color(char c, t_all *a);
int					*rft_get_clr(char c, t_all *a);
int					*rf_reg_ok(char c, t_all *a);
int					ft_reg_ok1(int i, char *str, int *m_ok);
int					stop_cub(t_all *a);
float				rft_init_angle_pos(t_list *base);
void				free_map(char **map);

void				ft_print_lines(char **lns, t_all *a);/*DELL*/
void				print_list(t_data *a);/*DELL*/
#endif
