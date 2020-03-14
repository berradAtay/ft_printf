/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:11:39 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 01:44:45 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		initialize_arg(t_arg *curr_arg)
{
	curr_arg->fill_char = ' ';
	curr_arg->just = 0;
	curr_arg->min_width = 0;
	curr_arg->precision = 0;
	curr_arg->point = 0;
}

static void		parse_flags(const char *format, t_arg *curr_arg)
{
	while (format[g_pos] == '0' || format[g_pos] == '-')
	{
		if (format[g_pos] == '0')
			curr_arg->fill_char = '0';
		else if (format[g_pos] == '-')
			curr_arg->just = 1;
		g_pos++;
	}
}

static void		parse_width(const char *format, t_arg *curr_arg)
{
	size_t	index;

	while (format[g_pos] == '*')
	{
		curr_arg->min_width = va_arg(g_params, int);
		if (curr_arg->min_width < 0)
		{
			curr_arg->min_width = -curr_arg->min_width;
			curr_arg->just = 1;
		}
		g_pos++;
	}
	index = g_pos;
	while (ft_isdigit(format[index]))
		index++;
	if (index != g_pos)
	{
		curr_arg->min_width = ft_atoi(&format[g_pos]);
		if (curr_arg->min_width < 0)
			curr_arg->min_width = 0;
	}
	g_pos = index;
}

static void		parse_precision(const char *format, t_arg *curr_arg)
{
	size_t index;

	while (format[g_pos] == '.')
	{
		curr_arg->point = 1;
		g_pos++;
		while (format[g_pos] == '*')
		{
			curr_arg->precision = va_arg(g_params, int);
			g_pos++;
		}
		index = g_pos;
		while (ft_isdigit(format[index]))
			index++;
		if (index != g_pos)
		{
			curr_arg->precision = ft_atoi(&format[g_pos]);
		}
		if (curr_arg->precision < 0)
		{
			curr_arg->precision = 0;
			curr_arg->point = 0;
		}
		g_pos = index;
	}
}

int				ft_arg_handler(const char *format)
{
	t_arg	*curr_arg;
	int		len;

	curr_arg = (t_arg *)malloc(sizeof(t_arg));
	len = 0;
	initialize_arg(curr_arg);
	g_pos++;
	parse_flags(format, curr_arg);
	parse_width(format, curr_arg);
	parse_precision(format, curr_arg);
	if (is_conversion(format[g_pos]))
		len = ft_conversion_dispatcher(format[g_pos++], curr_arg);
	free(curr_arg);
	return (len);
}
