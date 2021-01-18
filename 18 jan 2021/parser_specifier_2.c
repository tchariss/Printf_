/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:57:16 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/14 19:57:47 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SPECIF "cspdiuxX%"

int			search_precis(t_flags *struct_pars, char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_atoi(str))
	{
		return (struct_pars->precis = 1);
	}
	return (i);
}

int			search_type(t_flags *struct_pars, char *str)
{
	int		i;
	char	sym;
	
	i = 0;
	if (ft_strchr(SPECIF, sym))
		return (struct_pars->type = 1);
	i++;
	return (i);
}
