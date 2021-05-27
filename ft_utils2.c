#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (47 < c && c < 58);
}

int		ft_run_counter(unsigned int nbr, int base)
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
