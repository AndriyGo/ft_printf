#include "ft_printf.h"
#include "../libft/libft.h"

char	*digit_for_int(int i)
{
	char	*ret;

	ret = ft_memalloc(2 * sizeof(char *));
	if (i <= 9)
		ret[0] = i + '0';
	else
		ret[0] =  (i - 10) + 'a';
	return (ret);
}

uintmax_t absolute(intmax_t num)
{
    if (num < 0)
        return (uintmax_t) (num * (-1));
    return (uintmax_t) num;
}

char	*num_to_base(intmax_t num, int base, t_format *flags)
{
	char	*ret;
	char	*cur;
	char	*tmp;

	if ((num == 0) && (flags->precision != 0))
    {
        ret = ft_strdup("0");
    }
	else
		ret = ft_strdup("");
	while (num != 0)
	{
		cur = digit_for_int(absolute(num) % base);
		tmp = ret;
		ret = ft_strjoin(cur, tmp);
		free(tmp);
		free(cur);
		num = num / base;
	}
    while ((flags->precision > 0) && (flags->precision > (int)ft_strlen(ret)))
    {
        tmp = ret;
        ret = ft_strjoin("0", tmp);
        free(tmp);
    }
	return (ret);
}

char    *num_to_base_u(uintmax_t num, int base, t_format *flags)
{
    char    *ret;
    char    *cur;
    char    *tmp;
    
    if ((num == 0) && (flags->precision != 0))
        ret = ft_strdup("0");
    else
        ret = ft_strdup("");
    while (num != 0)
    {
        cur = digit_for_int(num % base);
        tmp = ret;
        ret = ft_strjoin(cur, tmp);
        free(tmp);
        free(cur);
        num = num / base;
    }
    while ((flags->precision > 0) && (flags->precision > (int)ft_strlen(ret)))
    {
        tmp = ret;
        ret = ft_strjoin("0", tmp);
        free(tmp);
    }
    return (ret);
}

void    capitalize(char *s)
{
    while (*s)
    {
        if ((*s >= 'a') && (*s <= 'z'))
        {
            *s = *s - 'a' + 'A';
        }
        s++;
    }
}
