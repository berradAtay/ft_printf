/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:30:09 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 00:53:08 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	size_t	len_1;
	size_t	len_2;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	join = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, len_1);
	ft_memcpy(join + len_1, s2, len_2 + 1);
	free(s1);
	free(s2);
	return (join);
}
