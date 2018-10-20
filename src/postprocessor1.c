#include "ft_printf.h"
#include "../libft/libft.h"

void    print_rep(char c, int n)
{
    while (n-- > 0)
        write(1, &c, 1);
}

void    print_left_padding(t_format *flags, char *prefix, int len)
{
    if (len < flags->min_width)
    {
        if (flags->neg_width == 1)
        {
            ft_putstr(prefix);
        }
        else 
        {
            if (flags->zero_pad == 1)
            {
                ft_putstr(prefix);
                if (flags->precision < 0)
                    print_rep('0', flags->min_width - len);
                else
                    print_rep(' ', flags->min_width - len);
            }
            else
            {
                print_rep(' ', flags->min_width - len);
                ft_putstr(prefix);
            }
        }
    }
    else
        ft_putstr(prefix);
}

void    print_right_padding(t_format *flags, int len)
{
    if (len < flags->min_width)
    {
        if (flags->neg_width == 1)
            print_rep(' ', flags->min_width - len);
    }
}

void	display_string(char *str, t_format *flags, char *prefix, int *count)
{
	int		len;

	len = ft_strlen(str) + ft_strlen(prefix);
    if (flags->type == 'X')
        capitalize(str);
    print_left_padding(flags, prefix, len);
    ft_putstr(str);
    print_right_padding(flags, len);
	*count += (len >= flags->min_width) ? len : flags->min_width;
}

int		compare(char c, char compare)
{
	if ((c == ft_toupper(compare)) || (c == ft_tolower(compare)))
		return (1);
	return (0);
}
