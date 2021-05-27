#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define DIGIT "0123456789"
# define LOWER "0123456789abcdef"
# define UPPER "0123456789ABCDEF"

typedef	struct	s_format
{
	int			width;
	int			prec;
	int			minus;
	int			zero;
	int			dot;
	int			neg;
	int			res;
	int			ptr;
	va_list		*ap;
}				t_fmt;

int				ft_printf(const char *fmt, ...);
void			ft_init_struct(t_fmt *f_fmt);
void			ft_run_converter(const char *fmt, t_fmt *f_fmt);
void			ft_run_parser(const char *fmt, t_fmt *f_fmt);
void			ft_run_c(t_fmt *fmt);
void			ft_run_s(t_fmt *fmt);
void			ft_run_p(t_fmt *fmt);
void			ft_run_diux(t_fmt *fmt, char c);
void			ft_run_pr(t_fmt *fmt);
int				ft_run_counter(unsigned int nbr, int base);
void			ft_putchar(char c);
void			ft_putchar_while(int n, char c);
int				ft_strlen(const char *s);
void			ft_putstr(char *str);
int				ft_isdigit(int c);
#endif
