#include "ft_printf.h"
#include "../libft/libft.h"

int		unicode_length(uint32_t c)
{
	if ((c >= 0) && (c <= 0x7f))
		return (1);
	else if ((c >=0x0080) && (c <= 0x07FF))
		return (2);
	else if ((c >=0x0800) && (c <= 0xFFFF))
		return (3);
	else if ((c >=0x010000) && (c <= 0x10FFFF))
		return (4);
	return (0);
}

void	print_unicode(uint32_t *str, t_format *flags, int *count)
{
	int	len;
	int	w;
	uint32_t *i;
	int f;

	len = 0;
	if (str == NULL)
	{
		flags->size = 0;
		print_string(str, flags, count);
		return ;
	}
	i = str;
	while ((*str != 0) && ((flags->precision == -1) || (flags->precision >= unicode_length(*str))))
	{
		len += unicode_length(*str);
		if (flags->precision != -1)
			flags->precision -= unicode_length(*str);
		str++;
	}
	flags->precision = -1;
	print_left_padding(flags, "", len);
	w = flags->min_width;
	flags->min_width = 0;
	f = 0;
	while ((*i != 0) && (f <= len))
		if ((((f += unicode_length(*i)) <= len) || (w == -1)))
		{
			print_unicode_char(*(i++), flags, count);
		}
	flags->min_width = w;
	print_right_padding(flags, "", len);
	*count += (w > len) ? (w - len) : 0;
}

void	print_unicode_char(uint32_t c, t_format *flags, int *count)
{
	if ((c >= 0) && (c <= 0x7f))
		print_1b_unicode(c, flags, count);
	else if ((c >=0x0080) && (c <= 0x07FF))
		print_2b_unicode(c, flags, count);
	else if ((c >=0x0800) && (c <= 0xFFFF))
		print_3b_unicode(c, flags, count);
	else if ((c >=0x010000) && (c <= 0x10FFFF))
		print_4b_unicode(c, flags, count);
}

void	print_string(char *str, t_format *flags, int *count)
{
    char    *str2;
    char    *tmp;

	if (flags->size == L)
	{
		print_unicode(str, flags, count);
		return ;
	}
    if (str == NULL)
        tmp = strdup("(null)");
    else
        tmp = str;
    if ((flags->precision >= 0) && (flags->precision < ft_strlen(tmp)))
    {
        str2 = ft_strsub(tmp, 0, flags->precision);
        flags->precision = -1;
        display_string(str2, flags, "", count);
        free(str2);
    }
	else
        display_string(tmp, flags, "", count);
    if (str == NULL)
        free(tmp);
}

void	print_char(char c, t_format *flags, int *count)
{
	flags->precision = -1;
	print_left_padding(flags, "", 1);
	write(1, &c, 1);
	print_right_padding(flags, "", 1);
	*count += (1 >= flags->min_width) ? 1 : flags->min_width;
}
