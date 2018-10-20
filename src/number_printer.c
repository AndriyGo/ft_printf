#include "ft_printf.h"
#include "../libft/libft.h"

char	*prefix(long long int num, t_format *flags, char *num_s)
{
	char *ret;

    ret = NULL;
	if (flags->alternate == 1)
	{
		if (((flags->type == 'x') && (num != 0)) || (flags->type == 'p'))
			ret = ft_strdup("0x");
		else if ((flags->type == 'X') && (num != 0))
			ret = ft_strdup("0X");
		else if ((compare(flags->type, 'o') == 1) && ((num != 0) || (flags->precision == 0)) && (*num_s != '0'))
			ret = ft_strdup("0");
	}
	if ((compare(flags->type, 'd') == 1) || (compare(flags->type, 'i') == 1))
	{
		if ((num >= 0) && (flags->sign_always == 1))
			ret = ft_strdup("+");
		else if ((num >= 0) && (flags->space == 1))
			ret = ft_strdup(" ");
        else if (num < 0)
            ret = ft_strdup("-");
	}
    if (ret == NULL)
        ret = ft_strdup("");
	return (ret);
}

void	print_number(intmax_t num, int base, t_format *flags, int *count)
{
	char	*str;
	char	*pref;

    if ((compare(flags->type, 'd') == 1) || (compare(flags->type, 'i') == 1))
        str = num_to_base(num, base, flags);
    else
        str = num_to_base_u(num, base, flags);
	pref = prefix(num, flags, str);
	display_string(str, flags, pref, count);
	free(pref);
	free(str);
}

void    cast_and_print_num(va_list *ap, int base, t_format *flags, int *count)
{
    if (flags->size == L)
        print_number(va_arg(*ap, long int), base, flags, count);
    else if (flags->size == LL)
        print_number(va_arg(*ap, long long int), base, flags, count);
    else if (flags->size == J)
        print_number(va_arg(*ap, intmax_t), base, flags, count);
    else if (flags->size == Z)
        print_number(va_arg(*ap, size_t), base, flags, count);
    else if (flags->size == HH)
        print_number((signed char)va_arg(*ap, int), base, flags, count);
    else if (flags->size == H)
        print_number((short int)va_arg(*ap, int), base, flags, count);
    else
        print_number(va_arg(*ap, int), base, flags, count);
}

void    cast_and_print_num_u(va_list *ap, int base, t_format *flags, int *count)
{
    if (flags->size == L)
        print_number(va_arg(*ap, unsigned long int), base, flags, count);
    else if (flags->size == LL)
        print_number(va_arg(*ap, unsigned long long int), base, flags, count);
    else if (flags->size == J)
        print_number(va_arg(*ap, uintmax_t), base, flags, count);
    else if (flags->size == Z)
        print_number(va_arg(*ap, size_t), base, flags, count);
    else if (flags->size == HH)
        print_number((unsigned char)va_arg(*ap, unsigned int), base, flags, count);
    else if (flags->size == H)
        print_number((unsigned short int)va_arg(*ap, unsigned int), base, flags, count);
    else
        print_number(va_arg(*ap, unsigned int), base, flags, count);
}

void	print_pointer(void *p, t_format *flags, int *count)
{
	flags->size = LL;
	flags->alternate = 1;
	print_number((long long int)p, 16, flags, count);
}
