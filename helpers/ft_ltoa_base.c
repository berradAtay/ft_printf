/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:54:18 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:52:01 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned long long	ft_abs(long long i)
{
	return (i < 0 ? -i : i);
}

static int					count_digits(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

static char					base_val(long long val)
{
	if (val < 10)
		return ('0' + val);
	val -= 10;
	return ('a' + val);
}

char						*ft_ltoa_base(long long n, int base)
{
	char				*num;
	int					digits;
	int					sign;
	unsigned long long	val;

	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0);
	val = ft_abs(n);
	digits = count_digits(val, base) + sign;
	if (!(num = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	num[digits] = '\0';
	while (val > 0)
	{
		num[--digits] = base_val(val % base);
		val /= base;
	}
	if (sign)
		num[--digits] = '-';
	return (num);
}
