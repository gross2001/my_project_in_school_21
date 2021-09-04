#include "ft_push_swap.h"

int	ft_lstfree(t_list **lst)
{
	t_list	*buf;
	t_list	*el;

	el = *lst;
	if (el == NULL)
		return (0);
	while (el)
	{
		buf = el->next;
		free(el);
		el = buf;
	}
	*lst = NULL;
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (size);
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

int	ft_isdigit(char *string)
{
	int	i;

	i = 0;
	if (((string[i] >= '0') && (string[i] <= '9')) || (string[i] == '-'))
		i++;
	else
		return (0);
	while (string[i])
	{
		if ((string[i] >= '0') && (string[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	while (*str && ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r')))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		result = *str + 10 * result - '0';
		str++;
	}	
	return (result * minus);
}

long int	ft_atoi_l(const char *str)
{
	long int	result;
	int			minus;

	result = 0;
	minus = 1;
	while (*str && ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r')))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		result = *str + 10 * result - '0';
		str++;
	}
	return (result * (long int)minus);
}
