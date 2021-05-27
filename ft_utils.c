#include "ft_printf.h"

void		ft_init_struct(t_fmt *f_fmt)
{
	f_fmt->width = 0;
	f_fmt->prec = -1;
	f_fmt->minus = 0;
	f_fmt->zero = 0;
	f_fmt->dot = 0;
	f_fmt->neg = 0;
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putchar_while(int n, char c)
{
	while (n-- > 0)
		ft_putchar(c);
}

int			ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	int st;

	st = 0;
	while (str[st] != '\0')
	{
		ft_putchar(str[st]);
		st++;
	}
}
