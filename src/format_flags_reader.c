#include "ft_printf.h"
#include "../libft/libft.h"

void		read_size(const char **size, t_format *ret)
{
	if (**size == 'h')
	{
		if (ret->size == H)
			ret->size = HH;
		else if (ret->size < H)
			ret->size = H;
	}
	else if (**size == 'l')
	{
        if (ret->size == L)
            ret->size = LL;
        else if (ret->size < L)
            ret->size = L;
	}
	else if (**size == 'j')
    {
        if (ret->size < J)
            ret->size = J;
    }
    else if (ret->size < Z)
            ret->size = Z;
}

int		read_number(const char **fmt)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(**fmt))
		ret = ret * 10 + (*((*fmt)++) - '0');
	(*fmt)--;
	return (ret);
}

t_format	*init_flags() {
	t_format	*ret;

	ret = malloc(sizeof(t_format));
	ret->size = 0;
	ret->type = -1;
	ret->min_width = 0;
	ret->precision = -1;
	ret->alternate = 0;
	ret->zero_pad = 0;
	ret->neg_width = 0;
	ret->space = 0;
	return (ret);
}

int		read_format_specifier(const char *fmt, t_format *flags)
{
	if ((*fmt == 's') || (*fmt == 'S') || (*fmt == 'p') || (*fmt == 'd') \
		|| (*fmt == 'D') || (*fmt == 'i') || (*fmt == 'o') || (*fmt == 'O') \
		|| (*fmt == 'u') || (*fmt == 'U') || (*fmt == 'x') || (*fmt == 'X') \
		|| (*fmt == 'c') || (*fmt == 'C') || (*fmt == '%'))
    {
		flags->type = *fmt;
        return (1);
    }
    return (0);
}

t_format	*read_format(const char **fmt, va_list *ap)
{
	t_format	*ret;

	ret = init_flags();
	while ((**fmt) && (ret->type == -1))
	{
		if (**fmt == '#')
			ret->alternate = 1;
		else if (**fmt == '0')
			ret->zero_pad = 1;
		else if (**fmt == '-')
			ret->neg_width = 1;
		else if (**fmt == ' ')
			ret->space = 1;
		else if (**fmt == '+')
			ret->sign_always = 1;
		else if (((**fmt == 'h') || (**fmt == 'l') || (**fmt == 'j') || (**fmt == 'z')))
            read_size(fmt, ret);
		else if ((**fmt >= '0') && (**fmt <= '9'))
			ret->min_width = read_number(fmt);
		else if (**fmt == '.')
		{
			(*fmt)++;
            if (**fmt == '*')
                ret->precision = va_arg(*ap, int);
            else
                ret->precision = read_number(fmt);
		}
        else if (**fmt == '*')
        {
            ret->min_width = va_arg(*ap, int);
            if (ret->min_width < 0)
            {
            	ret->min_width *= -1;
            	ret->neg_width = 1;
            }
        }
		else if (read_format_specifier(*fmt, ret) == 0)
            break ;
		(*fmt)++;	
	}
	return (ret);
}
