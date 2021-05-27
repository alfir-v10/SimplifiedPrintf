#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_fmt	f_fmt;

	f_fmt.ptr = 0;
	f_fmt.res = 0;
	f_fmt.ap = &ap;
	ft_init_struct(&f_fmt);
	va_start(ap, fmt);
	while (fmt[f_fmt.ptr])
	{
		if (fmt[f_fmt.ptr] == '%')
		{
			ft_run_converter(fmt, &f_fmt);
		}
		else
		{
			ft_putchar(fmt[f_fmt.ptr]);
			f_fmt.res++;
		}
		f_fmt.ptr++;
	}
	va_end(*f_fmt.ap);
	return (f_fmt.res);
}
