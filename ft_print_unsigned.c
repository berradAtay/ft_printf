/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:06:40 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 01:46:11 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_unsigned(unsigned int val, int base, t_arg *curr_arg)
{
	char	*val_str;
	size_t	val_len;

	if (!val && !curr_arg->precision && curr_arg->point)
		val_str = ft_strdup("");
	else
	{
		val_str = ft_ltoa_base(val, base);
		if ((val_len = ft_strlen(val_str)) < (size_t)curr_arg->precision)
			val_str = ft_strjoin_free(ft_strgen('0',
				curr_arg->precision - val_len), val_str);
	}
	if ((val_len = ft_strlen(val_str)) < (size_t)curr_arg->min_width)
	{
		if (curr_arg->point)
			curr_arg->fill_char = ' ';
		if (curr_arg->just)
			val_str = ft_strjoin_free(val_str,
				ft_strgen(' ', curr_arg->min_width - val_len));
		else
			val_str = ft_strjoin_free(ft_strgen(curr_arg->fill_char,
				curr_arg->min_width - val_len), val_str);
	}
	return (val_str);
}

int			ft_print_unsigned(int base, int maj, t_arg *curr_arg)
{
	char			*out;
	unsigned int	val;
	size_t			i;
	int				len;

	val = va_arg(g_params, unsigned int);
	out = parse_unsigned(val, base, curr_arg);
	if (base == 16)
		if (maj)
		{
			i = 0;
			while (out[i])
			{
				out[i] = ft_toupper(out[i]);
				i++;
			}
		}
	ft_putstr_fd(out, 1);
	len = (int)ft_strlen(out);
	free(out);
	return (len);
}
