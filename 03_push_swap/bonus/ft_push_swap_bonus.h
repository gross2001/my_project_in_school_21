#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include	"../mandatory/ft_push_swap.h"
# include	"gnl/get_next_line.h"

int	ft_take_line(t_list **el, t_list **elb);
int	ft_run_commands(char *line, t_list **el, t_list **elb);
int	ft_strncmp(const char *s1, const char *s2);
int	ft_s_bonus(t_list **lst);
int	ft_rr_bonus(t_list **lst);
int	ft_r_bonus(t_list **lst);
int	ft_p_bonus(t_list **lsta, t_list **lstb);
int	ft_is_it_sorted(t_list *el, t_list *elb);

#endif
