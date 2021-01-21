/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:49:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 14:01:58 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIF "cspdiuxX%"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flags
{
	char	*str;
	int		num;
	int 	minus; // char flag
	int		zero;
	int		width;
	int		tochnost; // (+ int dot)
	int		mark_tochnost;
	char	type;
	
}					t_flags;
//-------------------------------------// parser
int			ft_printf(const char *str, ...);
void		*ft_calloc(size_t count, size_t size);
int			parser(t_flags *str_spec, va_list v1);
void		search_flag(t_flags *struct_pars);
void		search_width(t_flags *str_spec, va_list v1);
void		search_tochnost(t_flags *str_spec, va_list v1);
char		*ft_strchr(char *s, char c);
void		search_type(t_flags *str_spec);
//-------------------------------------// 
void		type_c(t_flags *str_spec, va_list v1);
int			ft_putchar_len(char c, int len);
void		type_s(t_flags *str_spec, va_list v1);
size_t		ft_strlen(const char *str);
int			ft_putstr(char *s, int len);
void		type_c(t_flags *str_spec, va_list v1);
void		type_persent(t_flags *str_spec, va_list v1);
int			ft_putstr_fd(char *s, int fd);

#endif