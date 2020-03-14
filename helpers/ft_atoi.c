/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:44:53 by ybichri           #+#    #+#             */
/*   Updated: 2019/11/17 21:56:13 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int res;
	int neg;

	neg = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if ((*str) == '+')
		str++;
	else if ((*str) == '-')
	{
		neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = res * 10;
		res += *str - '0';
		str++;
	}
	return (res * neg);
}
