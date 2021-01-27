/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:49:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 00:55:32 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIF "cspdiuxX%"
// # define MAX_INT 2147483647
// # define MIN_INT -2147483648

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
void		search_flag(t_flags *str_spec);
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
void		type_persent(t_flags *str_spec);
int			ft_putnbr(int nb, t_flags *str_spec);
int			ft_putnbr_unsigned(unsigned long long nb, t_flags *str_spec);
char		*ft_itoa(unsigned int n);
int			ft_digit_strlen(int digit);
int			ft_digit_unsigned_strlen(unsigned int digit);
void		type_di(t_flags *str_spec, va_list v1);
void		type_u(t_flags *str_spec, va_list v1);
void		type_xX(t_flags *str_spec, va_list v1);
void		ft_16_putnbr(unsigned long long digit, char c, t_flags *str_spec);
int			ft_strlen_16(unsigned long long digit);
void		type_p(t_flags *str_spec, va_list v1);

#endif
