/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:41:22 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 17:52:50 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	null_char(t_arg *curr_arg)
{
	char	*str;
	int		len;

	len = 1;
	if (curr_arg->min_width > 1)
	{
		len = curr_arg->min_width;
		if (curr_arg->just)
		{
			write(1, "\0", 1);
			str = ft_strgen(' ', len - 1);
			ft_putstr_fd(str, 1);
		}
		else
		{
			str = ft_strgen(curr_arg->fill_char, len - 1);
			ft_putstr_fd(str, 1);
			write(1, "\0", 1);
		}
		free(str);
	}
	else
		ft_putchar_fd(0, 1);
	return (len);
}

static char	*parse_char(unsigned char val, t_arg *curr_arg)
{
	char	*val_str;

	val_str = ft_strgen(val, 1);
	if (curr_arg->min_width > 1)
	{
		if (curr_arg->just)
			val_str = ft_strjoin_free(val_str,
				ft_strgen(' ', curr_arg->min_width - 1));
		else
			val_str = ft_strjoin_free(ft_strgen(curr_arg->fill_char,
				curr_arg->min_width - 1), val_str);
	}
	return (val_str);
}

int			ft_print_char(unsigned char c, int flag, t_arg *curr_arg)
{
	char			*out;
	unsigned char	val;
	int				len;

	if (!flag)
		val = (unsigned char)va_arg(g_params, int);
	else
		val = c;
	if (val)
	{
		out = parse_char(val, curr_arg);
		ft_putstr_fd(out, 1);
		len = (int)ft_strlen(out);
		free(out);
	}
	else
		len = null_char(curr_arg);
	return (len);
}
