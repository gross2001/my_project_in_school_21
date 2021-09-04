#include "ft_printf.h"
#include <stdio.h>

int      main()
{
	char *text = "some teeeeeext";
	
	ft_printf("|%40.40s|\n", text);
	ft_printf("|%40.5s|\n", text);

	ft_printf("|%10.4i plus %3.4i equal %i|\n", 42, 42, 84);

}
