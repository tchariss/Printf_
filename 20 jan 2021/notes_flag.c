/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:37:20 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 11:51:47 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SPECIF "cspdiuxX%"
#define FLAG "-0"

char	*ft_strchr(char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

int	note_flag(t_flags *struct_pars)
{
	if (width > precis) // 5 и 3 
		precis - width // вычесть 5 - 3
		заполнить " " 2 места пустых
	
	if (width < 0) // -6 
		width = flag_minus // - как флаг // 6 ширина
	
	// в string // точность
	if (precis) // если точность существует
	(len > precis) // 7 и 4 // Nikolas
	return (precis) // 4 // Niko 
		:
		return (len) // 7 //Nikolas
	else // len < precis 
		return (len) // Nikolas
}