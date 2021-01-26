/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:03:38 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/22 08:28:49 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_calloc(size_t count, size_t size)
{
	int		*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	while (i < count)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
