#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include  <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_data
{
	int				x;
	int				y;
	char			content;
	struct s_data	*next;
}				t_data;

typedef struct s_list {
	int		width;
	int		height;
	int		x_pos;
	int		y_pos;
	int		number_of_move;
	int		exit_numb;
	int		collect_numb;
	int		position_numb;
	int		i_get_collect;
	int		is_map_checked;
	int		finish;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*map_exit;
	void	*space;
	void	*collect;
	void	*position;
	t_data	*map;
}				t_list;

t_data	*ft_lstnew(int x, int y, char content);
t_data	*ft_lstlast(t_data *lst);
t_data	*ft_create_map(int fd, t_list *base);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	ft_is_it_allowed(t_data *map, int x, int y);
int		ft_check_map(t_data *lst, t_list *base);
int		ft_images_to_map(t_data *lst, t_list *base);
int		ft_find_position(t_list *base);
int		ft_find_size_map(t_list *base);
int		ft_map_error(t_list *base);
int		ft_check_extension(char *string);
int		ft_close(t_list *base);
int		key_hook(int keycode, t_list *base);
int		ft_do_move(t_list *base, int x, int y);
int		ft_change_content(t_data **map, int x, int y);
int		ft_display_move(t_list *base, int x, int y);
int		ft_load_images(t_list *base);
int		ft_lstfree(t_data **lst);
int		ft_initialize_base(int argc, t_list *base);
int		ft_initialize_mlx(t_list *base);

#endif
