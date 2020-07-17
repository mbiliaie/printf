/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_b_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:33:05 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:33:10 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static short	bit_handler(t_char *b)
{
	if (b->bt_s == 2)
	{
		b->a_1 = ((b->c >> 6) << 27) >> 27;
		b->a_2 = STL_26;
	}
	else if (b->bt_s == 3)
	{
		b->a_1 = ((b->c >> 12) << 28) >> 28;
		b->a_2 = ST_26;
		b->a_3 = STL_26;
	}
	else
	{
		b->a_1 = ((b->c >> 18) << 29) >> 29;
		b->a_2 = ((b->c >> 12) << 26) >> 26;
		b->a_3 = ST_26;
		b->a_4 = STL_26;
	}
	return (0);
}

short			load_bit_symbol(struct s_gen *a_start, t_char *b, short bt_s)
{
	if ((b->bt_s = bt_s) == 2)
	{
		VAL_MX2;
		bit_handler(b);
		load_symbol(a_start, ((b->b_mx2 >> 8) | b->a_1));
		load_symbol(a_start, (((b->b_mx2 << 24) >> 24) | b->a_2));
	}
	else if (b->bt_s == 3)
	{
		VAL_MX3;
		bit_handler(b);
		load_symbol(a_start, (b->b_mx3 >> 16) | b->a_1);
		load_symbol(a_start, ((b->b_mx3 << 16) >> 24) | b->a_2);
		load_symbol(a_start, ((b->b_mx3 << 24) >> 24) | b->a_3);
	}
	else
	{
		VAL_MX4;
		bit_handler(b);
		load_symbol(a_start, (b->b_mx4 >> 24) | b->a_1);
		load_symbol(a_start, ((b->b_mx4 << 8) >> 24) | b->a_2);
		load_symbol(a_start, ((b->b_mx4 << 16) >> 24) | b->a_3);
		load_symbol(a_start, ((b->b_mx4 << 24) >> 24) | b->a_4);
	}
	return (0);
}
