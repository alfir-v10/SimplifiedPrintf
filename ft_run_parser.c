#include "ft_printf.h"

static int			ft_pars_nbr(const char *fmt, int *ptr)
{
	int	nb;

	nb = 0;
	while (ft_isdigit(fmt[*ptr]))
	{
		nb = nb * 10 + fmt[*ptr] - '0';
		(*ptr)++;
	}
	return (nb);
}

static void			ft_run_precision(const char *fmt, t_fmt *f_fmt)
{
	f_fmt->ptr++;
	f_fmt->dot = 1;
	if (fmt[f_fmt->ptr] == '*')
	{
		f_fmt->prec = va_arg(*f_fmt->ap, int);
		if (f_fmt->prec < 0)
		{
			f_fmt->dot = 0;
			f_fmt->prec = -1;
		}
		if (f_fmt->prec >= 0)
			f_fmt->zero = 0;
		f_fmt->ptr++;
	}
	else
	{
		if (ft_isdigit(fmt[f_fmt->ptr]))
		{
			f_fmt->zero = 0;
			f_fmt->prec = ft_pars_nbr(fmt, &f_fmt->ptr);
		}
	}
}

static void			ft_run_width(const char *fmt, t_fmt *f_fmt)
{
	if (fmt[f_fmt->ptr] == '*')
	{
		f_fmt->width = va_arg(*f_fmt->ap, int);
		if (f_fmt->width < 0)
		{
			f_fmt->minus = 1;
			f_fmt->zero = 0;
			f_fmt->width *= -1;
		}
		f_fmt->ptr++;
	}
	else
		f_fmt->width = ft_pars_nbr(fmt, &f_fmt->ptr);
}

static void			ft_run_flag(const char *fmt, t_fmt *f_fmt)
{
	while (fmt[f_fmt->ptr] == '-' || fmt[f_fmt->ptr] == '0')
	{
		if (fmt[f_fmt->ptr] == '-')
			f_fmt->minus = 1;
		if (fmt[f_fmt->ptr] == '0' && !f_fmt->minus)
			f_fmt->zero = 1;
		f_fmt->ptr++;
	}
}

void				ft_run_parser(const char *fmt, t_fmt *f_fmt)
{
	f_fmt->ptr++;
	if (fmt[f_fmt->ptr] == '-' || fmt[f_fmt->ptr] == '0')
		ft_run_flag(fmt, f_fmt);
	ft_run_width(fmt, f_fmt);
	if (fmt[f_fmt->ptr] == '.')
		ft_run_precision(fmt, f_fmt);
}
