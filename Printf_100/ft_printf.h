/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:49:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/28 14:57:33 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIF "cspdiuxX%"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flags
{
	char		*str;
	int			num;
	int			minus;
	int			zero;
	int			width;
	int			tochnost;
	int			mark_tochnost;
	char		type;
}					t_flags;

int					ft_printf(const char *str, ...);
void				*ft_calloc(size_t count, size_t size);
int					parser(t_flags *str_spec, va_list v1);
void				search_flag(t_flags *str_spec);
void				search_width(t_flags *str_spec, va_list v1);
void				search_tochnost(t_flags *str_spec, va_list v1);
char				*ft_strchr(char *s, char c);
void				search_type(t_flags *str_spec);
void				type_c(t_flags *str_spec, va_list v1);
int					ft_putchar_len(char c, int len);
void				type_s(t_flags *str_spec, va_list v1);
size_t				ft_strlen(const char *str);
int					ft_putstr(char *s, int len);
void				type_c(t_flags *str_spec, va_list v1);
void				type_persent(t_flags *str_spec);
int					ft_putnbr(long long nb, t_flags *str_spec);
int					ft_putnbr_unsigned(unsigned long long nb,
														t_flags *str_spec);
char				*ft_itoa(unsigned int n);
int					ft_digit_strlen(long digit);
int					ft_digit_unsigned_strlen(unsigned int digit);
void				type_di(t_flags *str_spec, va_list v1);
void				type_u(t_flags *str_spec, va_list v1);
void				type_x(t_flags *str_spec, va_list v1);
void				ft_16_putnbr(unsigned long long digit, char c,
														t_flags *str_spec);
int					ft_strlen_16(unsigned long long digit);
void				type_p(t_flags *str_spec, va_list v1);
void				minus_or_width_neg_p(long unsigned i, int len, char *s,
														t_flags *str_spec);
void				minus_or_width_neg_di(int i, int len, t_flags *str_spec);
char				*ft_strdup(const char *s1);

#endif
