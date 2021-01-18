/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:39:49 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 13:44:02 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #define SPECIF "cspdiuxX%"

// #include "ft_printf.c"
// int	search_persent(va_list v1, const char *str)
// return (i)	
int			search_percent(t_flags *str_spec, char *str)
{
	char	per;
	int		i;
	
	i = 0;
	per = '%';
	if (!str[i])
		write(1, "(null)", 6);
	while (str[i] && str[i] != per)
	{
		write(1, &str[i], 1); // пока не нашли % , записываем все
		i++;
	}
	if (str[i] && str[i] == per)
	{
		return (str_spec->per = 1);
		i++;
	}
	return (i);
}

int			search_flag(t_flags *struct_pars, char *str, va_list v1)
{
	int		i;
	// char	per;
	char	zero;
	char	minus;

	i = 0;
	// per = '%';
	zero = '0';
	minus = '-';
	// if (str[i] && str[i] == per)
	// {
	// 	i++;
		if (str[i] == minus)
			struct_pars->minus = 1; // return (1);
		if (str[i] == zero)// str = '0'
			struct_pars->zero = 1; //return (1);
		// if (*str == minus && *str == zero)
		// return(1);
	// }
	return (i);
}

int			search_width(t_flags *struct_pars, char *str, va_list v1)
{
	int		i;

	i = 0;
	while (str[i] && ft_atoi(str))
	{
		return (struct_pars->width = 1);
	} 
	return (i);
}

int			search_dot(t_flags *struct_pars, char *str)
{
	int		i;
	char	dot;

	i = 0;
	dot = '.';
	if (str[i] && str[i] == dot)
	{
		i++; // .. str[i++] == dot
		return (struct_pars->dot = 1);
	}
	return (i);
}

int			search_precis(t_flags *struct_pars, char *str, va_list v1)
{
	int		i;

	i = 0;
	while (str[i] && ft_atoi(str))
	{
		if (ft_isdigit(str))
			return (struct_pars->precis = 1);
	}
	return (i);
}

int			search_type(t_flags *struct_pars, char *str, va_list v1)
{
	int		i;
	char	sym;
	
	i = 0;
	sym = '\0';
	if (str[i] && ft_strchr(SPECIF, sym))
		return (struct_pars->type = 1);
	i++;
	return (i);
}

int	main()
{
	ft_printf("-5.2%s", "viktorina");
	//-----------------------------
	// printf("-5.2%s", "viktorina");
}