/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:39:29 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:53:16 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		a;
	int		b;

	a = 0;
	b = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == 0)
		return (NULL);
	while (s1[a] != '\0')
	{
		s2[b] = s1[a];
		a++;
		b++;
	}
	s2[b] = '\0';
	return (s2);
}
