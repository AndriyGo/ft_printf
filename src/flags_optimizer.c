#include "ft_printf.h"

void	optimise_flags(t_format *flags)
{
	if (flags->type == 'S')
	{
		flags->type = 's';
		flags->size = L;
	}
	else if (flags->type == 'C')
	{
		flags->type = 'c';
		flags->size = L;
	}
	else if (flags->type == 'D')
	{
		flags->type = 'd';
		flags->size = L;
	}
	else if (flags->type == 'O')
	{
		flags->type = 'o';
		flags->size = L;
	}
	else if (flags->type == 'U')
	{
		flags->type = 'u';
		flags->size = L;
	}
    if (flags->neg_width == 1)
        flags->zero_pad = 0;
}
