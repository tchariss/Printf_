/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:03:38 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/28 16:40:22 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	a;

	a = 0;
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	while (a < count * size)
	{
		p[a] = '\0';
		a++;
	}
	return (p);
}
