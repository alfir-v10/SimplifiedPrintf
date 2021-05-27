#include "ft_printf.h"

static void		ft_run_conv(t_fmt *f_fmt, char c)
{
	if (c == 'c')
		ft_run_c(f_fmt);
	if (c == 's')
		ft_run_s(f_fmt);
	if (c == 'p')
		ft_run_p(f_fmt);
}

void			ft_run_converter(const char *fmt, t_fmt *f_fmt)
{
	char c;

	ft_run_parser(fmt, f_fmt);
	c = fmt[f_fmt->ptr];
	if (c == 'c' || c == 's' || c == 'p')
		ft_run_conv(f_fmt, c);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ft_run_diux(f_fmt, c);
	else if (c)
	{
		if (c == '%')
			ft_run_pr(f_fmt);
		else
		{
			ft_putchar('%');
			f_fmt->ptr--;
			f_fmt->res++;
		}
	}
	else
		f_fmt->ptr--;
	ft_init_struct(f_fmt);
}
