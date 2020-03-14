/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:54:21 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:53:10 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strgen(char c, size_t len)
{
	char *str;

	if (len <= 0)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}
