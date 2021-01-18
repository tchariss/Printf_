/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:49:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 13:49:42 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// # define SPECIF "cspdiuxX%"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flags
{
	int		percent;
	char	flag;
	int		width;
	// int dot;
	int		precis; //(+ int dot)
	char	type;
	int		lenght;
}					t_flags;

int		parser(char *s, t_flags *str_spec, va_list v1);
int		search_percent(t_flags	*str_pars, char *str);
int		search_flag(t_flags *str_pars, char *str);
char	*search_spec(char *str);
int		search_width(t_flags *struct_pars, char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		search_dot(t_flags *struct_pars, char *str);
int		search_precis(t_flags *struct_pars, char *str);
char	*ft_strchr(char *s, char c);
int		search_type(t_flags *struct_pars, char *str);
int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t count, size_t size);

#endif