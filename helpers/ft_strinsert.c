/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:16:11 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:53:09 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** inserts s2 into the index pos of s1 and frees s1 and s2
** ps. 0 based indexing
*/

char	*ft_strinsert(char *s1, size_t pos, char *s2)
{
	char	*res;
	size_t	len_1;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	res = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, pos);
	ft_memcpy(res + pos, s2, len_2);
	ft_memcpy(res + pos + len_2, s1 + pos, len_1 - pos + 1);
	free(s1);
	free(s2);
	return (res);
}
