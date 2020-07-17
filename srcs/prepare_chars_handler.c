/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_chars_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:06:07 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:06:13 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned char			find_bits_used(int chr)
{
	unsigned char		k;
	unsigned char		j;
	unsigned char		o;
	unsigned char		bits;

	j = OCT * sizeof(size_t);
	o = 0;
	k = 1;
	while (k < j && (unsigned int)chr >> k)
	{
		k = k + 1;
	}
	if (j == k)
	{
		bits = o;
		return (bits);
	}
	else
	{
		bits = k;
		return (bits);
	}
}

unsigned char			find_bytes_used(int chr)
{
	char				ln_chr;
	unsigned char		bytes;

	bytes = 0;
	if (((ln_chr = find_bits_used(chr)) >= 17) && ln_chr < 33)
	{
		bytes = 4;
		return (bytes);
	}
	else if (ln_chr >= 12 && ln_chr < 17)
	{
		bytes = 3;
		return (bytes);
	}
	else if (ln_chr >= 8 && ln_chr < 12)
	{
		bytes = 2;
		return (bytes);
	}
	else if (ln_chr < 8)
	{
		bytes = 1;
		return (bytes);
	}
	return (bytes);
}

void					get_char_params(struct s_gen *a, int chr, t_char *c)
{
	c->c = (unsigned int)chr;
	c->bts_2 = 2;
	c->bts_3 = 3;
	c->bts_4 = 4;
	c->bts_used = find_bytes_used(chr);
	c->ln_chr = find_bits_used(chr);
	c->lcl = MB_CUR_MAX;
	if (a->m.f_zr)
		c->fil_chr = '0';
	else
		c->fil_chr = ' ';
}

void					prepare_char_handler(struct s_gen *a_start, char y)
{
	if (CFL == 'c')
	{
		if (a_start->m.l || a_start->m.l2)
			chars_display(a_start, va_arg(a_start->ap, int));
		else
			chars_display(a_start, (char)va_arg(a_start->ap, int));
	}
	else
		chars_display(a_start, y);
}
