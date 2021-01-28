/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:20:35 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 15:48:31 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					nbr(unsigned int n)
{
	int				i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(unsigned int n)
{
	char			*res;
	unsigned int	len;

	len = nbr(n);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[len--] = '\0';
	while (n > 9)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	res[len] = n % 10 + '0';
	free(res);
	return (res);
	res = NULL;
}
