/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:27:14 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 18:05:55 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*null_pointer(t_arg *curr_arg)
{
	char *str;

	if (curr_arg->precision)
		str = ft_strgen('0', curr_arg->precision);
	else if (curr_arg->point)
		str = ft_strdup("");
	else
		str = ft_strgen('0', 1);
	return (str);
}

static char	*parse_pointer(long long val, t_arg *curr_arg)
{
	char	*val_str;
	int		pos;
	size_t	val_len;

	pos = 0;
	val_str = ft_strdup("0x");
	if (!val)
		val_str = ft_strjoin_free(val_str, null_pointer(curr_arg));
	else
		val_str = ft_strjoin_free(val_str, ft_ltoa_base(val, 16));
	if ((size_t)curr_arg->min_width > (val_len = ft_strlen(val_str)))
	{
		if (curr_arg->just)
			val_str = ft_strjoin_free(val_str,
				ft_strgen(' ', curr_arg->min_width - val_len));
		else
		{
			if (curr_arg->fill_char == '0')
				pos = 2;
			val_str = ft_strinsert(val_str, pos,
			ft_strgen(curr_arg->fill_char, curr_arg->min_width - val_len));
		}
	}
	return (val_str);
}

int			ft_print_pointer(t_arg *curr_arg)
{
	char			*out;
	long long		val;
	int				len;

	val = (long long)va_arg(g_params, void *);
	out = parse_pointer(val, curr_arg);
	ft_putstr_fd(out, 1);
	len = (int)ft_strlen(out);
	free(out);
	return (len);
}
