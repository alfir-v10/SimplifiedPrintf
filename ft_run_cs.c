#include "ft_printf.h"

void			ft_run_c(t_fmt *f_fmt)
{
	char	c;
	int		n;

	c = va_arg(*f_fmt->ap, int);
	n = 0;
	if (f_fmt->width > 1)
		n = f_fmt->width - 1;
	f_fmt->res += 1 + n;
	if (!f_fmt->minus)
		ft_putchar_while(n, ' ');
	ft_putchar(c);
	if (f_fmt->minus)
		ft_putchar_while(n, ' ');
}

static int		ft_strlen_mod(t_fmt *f_fmt, char *s)
{
	int n;
	int prec;
	int len;

	prec = f_fmt->prec;
	len = ft_strlen(s);
	n = 0;
	if (prec > 0 && prec < len)
		n = prec;
	else
	{
		if (!(f_fmt->dot && prec <= 0))
			n = len;
	}
	return (n);
}

static int		ft_output_zero(t_fmt *f_fmt, int n)
{
	int ret;

	ret = 0;
	if (f_fmt->width > n && f_fmt->zero)
		ret = f_fmt->width - n;
	return (ret);
}

static int		ft_output_space(t_fmt *f_fmt, int n, int m)
{
	int ret;

	ret = 0;
	if (f_fmt->width > n && !m)
		ret = f_fmt->width - n;
	return (ret);
}

void			ft_run_s(t_fmt *f_fmt)
{
	char	*s;
	int		k;
	int		m;
	int		n;

	if (!(s = va_arg(*f_fmt->ap, char*)))
		s = "(null)";
	k = ft_strlen_mod(f_fmt, s);
	m = ft_output_zero(f_fmt, k);
	n = ft_output_space(f_fmt, k, m);
	f_fmt->res += k + m + n;
	if (!f_fmt->minus)
		ft_putchar_while(n, ' ');
	if (f_fmt->zero)
		ft_putchar_while(m, '0');
	while (k--)
		ft_putchar(*s++);
	if (f_fmt->minus)
		ft_putchar_while(n, ' ');
}
