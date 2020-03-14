/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:43:03 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 01:46:03 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_str(const char *val, t_arg *curr_arg)
{
	char	*val_str;
	char	*tmp;
	size_t	val_len;

	if (!val)
		val_str = ft_strdup("(null)");
	else
		val_str = ft_strdup(val);
	val_len = ft_strlen(val_str);
	if (curr_arg->point && val_len > (size_t)curr_arg->precision)
	{
		tmp = val_str;
		val_str = ft_substr(val_str, 0, curr_arg->precision);
		free(tmp);
	}
	if ((val_len = ft_strlen(val_str)) < (size_t)curr_arg->min_width)
	{
		if (curr_arg->just)
			val_str = ft_strjoin_free(val_str,
				ft_strgen(' ', curr_arg->min_width - val_len));
		else
			val_str = ft_strjoin_free(ft_strgen(curr_arg->fill_char,
				curr_arg->min_width - val_len), val_str);
	}
	return (val_str);
}

int			ft_print_str(t_arg *curr_arg)
{
	char			*out;
	const char		*val;
	int				len;

	val = va_arg(g_params, const char *);
	out = parse_str(val, curr_arg);
	ft_putstr_fd(out, 1);
	len = (int)ft_strlen(out);
	free(out);
	return (len);
}
