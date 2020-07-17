/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_chars_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:24:33 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:24:36 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

short int	chars_display(struct s_gen *a_start, int y)
{
	t_char c;

	get_char_params(a_start, y, &c);
	if (CFL != 's')
	{
		while (!a_start->m.f_mns && a_start->m.f_ln && \
			a_start->m.f_ln > c.bts_used)
		{
			load_symbol(a_start, c.fil_chr);
			a_start->m.f_ln--;
		}
	}
	if (c.lcl > 0 && c.ln_chr < 8)
		load_symbol(a_start, y);
	else if (c.lcl > 1 && c.ln_chr < 12)
		load_bit_symbol(a_start, &c, c.bts_2);
	else if (c.lcl > 2 && c.ln_chr < 17)
		load_bit_symbol(a_start, &c, c.bts_3);
	else if (c.lcl > 3 && c.ln_chr < 33)
		load_bit_symbol(a_start, &c, c.bts_4);
	if (CFL != 's')
		while (a_start->m.f_mns && a_start->m.f_ln && \
			a_start->m.f_ln-- > c.bts_used)
			load_symbol(a_start, ' ');
	return (0);
}
