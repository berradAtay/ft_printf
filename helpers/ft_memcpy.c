/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:51:18 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:55:14 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char *des;
	unsigned char *sr;

	if (dest == NULL && src == NULL)
		return (NULL);
	des = (unsigned char*)dest;
	sr = (unsigned char*)src;
	while (len-- > 0)
		*des++ = *sr++;
	return (dest);
}
