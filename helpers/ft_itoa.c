/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 02:02:32 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:51:36 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

static int	count_digits(unsigned int n)
{
	int				count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*num;
	int				digits;
	int				sign;
	unsigned int	val;

	sign = 0;
	val = ft_abs(n);
	digits = count_digits(val);
	if (n < 0)
	{
		sign = 1;
		digits += 1;
	}
	if (!(num = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	num[digits] = '\0';
	while (val >= 10)
	{
		num[--digits] = '0' + val % 10;
		val /= 10;
	}
	num[--digits] = '0' + val % 10;
	if (sign)
		num[--digits] = '-';
	return (num);
}
