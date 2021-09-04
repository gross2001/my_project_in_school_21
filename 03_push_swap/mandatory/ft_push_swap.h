#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stddef.h>
# include	<stdlib.h>

typedef struct s_list
{
	int				number;
	int				group;
	int				min_number;
	int				max_number;
	struct s_list	*next;
}	t_list;

long int	ft_atoi_l(const char *str);
t_list		*ft_lstnew(int number);
t_list		*ft_lstcopy(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
size_t		ft_strlen(const char *s);
float		ft_update_min_max(t_list **lst);
float		ft_find_median(t_list *el, float median);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_to_a(t_list **el, t_list **elb);
void		ft_to_b(t_list **el, t_list **elb);

int			ft_small_group(char *argv[]);
int			ft_check_arg(int argc, char *argv[]);
int			ft_isdigit(char *string);
int			ft_atoi(const char *str);
int			ft_s(t_list **lst, char ch);
int			ft_rr(t_list **lst, char ch);
int			ft_r(t_list **lst, char ch);
int			ft_p(t_list **lsta, t_list **lstb, char ch);
int			ft_algorithm(t_list **el, t_list **elb);
int			ft_divide_median(t_list **el, t_list **elb, float median);
int			ft_come_back(t_list **el, t_list **elb, int come_back);
int			ft_come_back_b(t_list **el, t_list **elb, int come_back);
int			ft_how_many_groups(t_list *el);
int			ft_check_sort(t_list *el);
int			ft_find_max(t_list *lst);
int			ft_find_min(t_list *lst);
int			ft_find_closest(t_list *el, float numb, int dir);
int			ft_lstfree(t_list **lst);

#endif
