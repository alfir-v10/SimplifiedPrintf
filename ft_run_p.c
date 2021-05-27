#include "ft_printf.h"

static int		ft_run_lcounter(unsigned long int nbr, int base)
{
	size_t ret;

	ret = 1;
	while (nbr / base > 0)
	{
		ret++;
		nbr /= base;
	}
	return (ret);
}

static void		ft_putlnbr(unsigned long int nbr, char *s)
{
	size_t ret;

	ret = ft_strlen(s);
	if (nbr / ret > 0)
		ft_putlnbr(nbr / ret, s);
	ft_putchar(s[nbr % ret]);
}

void			ft_run_p(t_fmt *f_fmt)
{
	unsigned long int	nbr;
	int					m;
	int					n;
	int					k;

	nbr = va_arg(*f_fmt->ap, unsigned long int);
	m = ft_run_lcounter(nbr, 16);
	n = (f_fmt->prec > m) ? f_fmt->prec - m : 0;
	if (f_fmt->dot && f_fmt->prec <= 0 && nbr == 0)
		m = 2;
	else
		m += 2;
	k = (f_fmt->width > m) ? f_fmt->width - m : 0;
	f_fmt->res += m + n + k;
	if (!f_fmt->minus)
		ft_putchar_while(k, ' ');
	ft_putstr("0x");
	ft_putchar_while(n, '0');
	if (m > 2 && !(f_fmt->dot && f_fmt->prec == -1))
		ft_putlnbr(nbr, LOWER);
	if (f_fmt->minus)
		ft_putchar_while(k, ' ');
}
