/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:45:08 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 15:45:14 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned short int		extract_arg_value(struct s_gen *a_start, char y)
{
	char				x;

	x = CFL;
	if (x == 'i' || x == 'd' || x == 'p' || x == 'u' || x == 'o' || x == 'x')
		prepare_int_handler(a_start);
	else if (x == 's')
		prepare_str_handler(a_start);
	else
		prepare_char_handler(a_start, y);
	return (1);
}

unsigned long			parce_in(struct s_gen *a_start, const char *format)
{
	unsigned long int	result_shift;

	result_shift = load_s_mods(a_start, format);
	return (result_shift);
}

static unsigned int		no_prcnt_print(const char *format)
{
	unsigned long int	len;

	len = ft_strlen(format);
	if (ft_strchr(format, '%') == NULL)
	{
		write(1, format, len);
		return ((int)len);
	}
	else
		return (0);
}

int						ft_printf(const char *format, ...)
{
	ssize_t				done;
	static char			mem_gen[MEMS];
	struct s_gen		a_start;

	done = no_prcnt_print(format);
	if (done != 0)
		return (int)(done);
	ft_memset(&a_start, 0, sizeof(a_start));
	a_start.total_str = mem_gen;
	va_start(a_start.ap, format);
	general_parcer(&a_start, format);
	va_end(a_start.ap);
	if (a_start.k != 0)
	{
		done = write(1, a_start.total_str, a_start.k);
		done = a_start.prtd_chr_num + done;
	}
	return (int)(done);
}
