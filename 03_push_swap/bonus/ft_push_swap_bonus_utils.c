#include "ft_push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (us1[i] && us2[i])
	{
		if (us1[i] != us2[i] || us1[i] == '\0' || us2[i] == '\0')
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
