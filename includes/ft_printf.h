/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 00:38:05 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/22 00:38:10 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# define MEMS 128
# define IN a_start->k
# define DN a_start->done
# define CFL a_start->cfl
# define VAL_MX2 b->b_mx2 = 49280
# define VAL_MX3 b->b_mx3 = 14712960
# define VAL_MX4 b->b_mx4 = 4034953344
# define OCT 8
# define DEC 10
# define HEX 16
# define STL_26 (b->c << 26) >> 26
# define ST_26 ((b->c >> 6) << 26) >> 26

struct				s_mods
{
	unsigned short	f_pls : 1;
	unsigned long	f_prc;
	unsigned short	f_mns : 1;
	unsigned long	f_ln;
	unsigned short	l : 1;
	unsigned short	h : 1;
	unsigned short	l2 : 1;
	unsigned short	h2 : 1;
	unsigned short	z : 1;
	unsigned short	j : 1;
	unsigned short	dot : 1;
	unsigned short	f_zr : 1;
	unsigned short	f_hsh : 1;
	unsigned short	f_spc : 1;
	unsigned short	xb_conv : 1;
	unsigned short	bzr : 1;
};

struct				s_gen
{
	struct s_mods	m;
	char			cfl;
	int				prtd_chr_num;
	unsigned long	k;
	unsigned long	done;
	char			*total_str;
	unsigned long	shift;
	va_list			ap;
};

typedef struct		s_str
{
	unsigned long	min_length;
	unsigned long	ln;
	char			fil_chr;
	char			*display_null;
	char			*s;
}					t_str;

typedef struct		s_wstr
{
	unsigned long	min_length;
	unsigned long	ln;
	unsigned long	j;
	unsigned long	bts_used_num;
	char			fil_chr;
}					t_wstr;

typedef struct		s_int
{
	unsigned long	u_arg_val;
	char			*sv;
	unsigned long	ln_arg;
	unsigned long	ln_m;
	char			fil_chr;
	unsigned short	ct_fl;
	unsigned short	fl_presence;
	unsigned long	i;
}					t_int;

typedef struct		s_char
{
	unsigned char	a_1;
	unsigned char	a_2;
	unsigned char	a_3;
	unsigned char	a_4;
	unsigned		b_mx2;
	unsigned		b_mx3;
	unsigned		b_mx4;
	unsigned		c;
	short			bt_s;
	short			bts_2;
	short			bts_3;
	short			bts_4;
	char			fil_chr;
	unsigned char	bts_used;
	char			ln_chr;
	int				lcl;
}					t_char;

int					ft_printf(const char *format, ...);
short				load_symbol(struct s_gen *a_start, int x);
void				general_parcer(struct s_gen *a, const char *frm);
unsigned long		parce_in(struct s_gen *a_start, const char *format);
unsigned short		extract_arg_value(struct s_gen *a_start, char y);
short				convert_uabs(struct s_gen *a, short n_sys, t_int *d);
void				prepare_str_handler(struct s_gen *a_start);
void				prepare_int_handler(struct s_gen *a_start);
void				prepare_char_handler(struct s_gen *a_start, char y);
unsigned long		prepare_wstrs_handler(struct s_gen *a, \
	wchar_t *f, t_wstr *p);
short				ints_flag_combiner(struct	s_gen *a_start, t_int *d);
void				get_char_params(struct s_gen *a, int chr, t_char *c);
void				get_wstr_params (struct s_gen *a, t_wstr *p, wchar_t *s);
ssize_t				get_s_arg_val(struct s_gen *a_start);
unsigned long		get_u_arg_val(struct s_gen *a_start);
unsigned long		load_s_mods(struct s_gen *a_start, const char *format);
unsigned long		get_wide_string_ln(wchar_t *frm, t_wstr *prms);
short				strs_output(struct s_gen *a, char *str, size_t len);
short				wstrs_output(struct s_gen *a, wchar_t *s, \
	size_t l, t_wstr *p);
short				chars_display(struct s_gen *a_start, int y);
short				wstrs_display(struct s_gen *a, wchar_t *s);
short				load_bit_symbol(struct s_gen *a, t_char *c, short bs);
unsigned char		find_bits_used(int c);
unsigned char		find_bytes_used(int c);
long long			atoi_extd(const char *str);
#endif
