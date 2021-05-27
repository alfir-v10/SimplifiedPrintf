#include "ft_printf.h"

static int		ft_parser_out(t_fmt *f_fmt, int *m, int *r, unsigned int n)
{
	int ret;

	ret = 0;
	if (f_fmt->neg)
		(*m)++;
	if (f_fmt->dot && f_fmt->prec <= 0 && !n)
		*m = 0;
	if (f_fmt->prec > *m)
		*r = f_fmt->prec - *m;
	else if (f_fmt->width > *m && f_fmt->zero)
		*r = f_fmt->width - *m;
	else
		*r = 0;
	if (*r > 0)
		*m = *m + *r;
	if (f_fmt->width > *m && !f_fmt->zero)
		ret = f_fmt->width - *m;
	return (ret);
}

static void		ft_putnbr_stat(unsigned int n, char *s)
{
	size_t	ret;

	ret = ft_strlen(s);
	if (n / ret > 0)
		ft_putnbr_stat(n / ret, s);
	ft_putchar(s[n % ret]);
}

static void		ft_output_flag(t_fmt *f_fmt, unsigned int n, int m, char *s)
{
	int r;
	int t;

	t = ft_parser_out(f_fmt, &m, &r, n);
	f_fmt->res += m + t;
	if (!f_fmt->minus)
		ft_putchar_while(t, ' ');
	f_fmt->neg ? ft_putchar('-') : 0;
	ft_putchar_while(r, '0');
	if (m)
		ft_putnbr_stat(n, s);
	if (f_fmt->minus)
		ft_putchar_while(t, ' ');
}

void			ft_run_diux(t_fmt *f_fmt, char c)
{
	int				nbr;
	unsigned int	unbr;

	if (c == 'd' || c == 'i')
	{
		nbr = va_arg(*f_fmt->ap, int);
		if (nbr < 0)
		{
			f_fmt->neg = 1;
			nbr = -nbr;
			f_fmt->prec += f_fmt->prec > 0 ? 1 : 0;
		}
		ft_output_flag(f_fmt, nbr, ft_run_counter(nbr, 10), DIGIT);
	}
	if (c == 'u' || c == 'x' || c == 'X')
	{
		unbr = va_arg(*f_fmt->ap, unsigned int);
		if (c == 'u')
			ft_output_flag(f_fmt, unbr, ft_run_counter(unbr, 10), DIGIT);
		if (c == 'x')
			ft_output_flag(f_fmt, unbr, ft_run_counter(unbr, 16), LOWER);
		if (c == 'X')
			ft_output_flag(f_fmt, unbr, ft_run_counter(unbr, 16), UPPER);
	}
}

void			ft_run_pr(t_fmt *f_fmt)
{
	int m;
	int n;

	n = 0;
	m = 0;
	if (f_fmt->width > 1 && f_fmt->zero)
		n = f_fmt->width - 1;
	if (f_fmt->width > 1 && !n)
		m = f_fmt->width - 1;
	f_fmt->res = f_fmt->res + m + n + 1;
	if (!f_fmt->minus)
		ft_putchar_while(m, ' ');
	if (f_fmt->zero)
		ft_putchar_while(n, '0');
	ft_putchar('%');
	if (f_fmt->minus)
		ft_putchar_while(m, ' ');
}
