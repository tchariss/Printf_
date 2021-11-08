/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/25 21:22:16 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		condition_1(t_flags *str_spec, int i)
{
	int len;
	
	len = ft_digit_strlen(i);
	if (i > 0)
	{
		if (i != 0)
		{
			str_spec->num += ft_putnbr(i, str_spec);
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
		if (str_spec->tochnost > len)
		{
			str_spec->width = str_spec->width * (-1);
			str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
		}
		else if (str_spec->tochnost < len)
		{	
			str_spec->num += ft_putchar_len(' ', str_spec->width - len); 
		}
	}
	if (i < 0) 
	{
		if (str_spec->width < 0)
			str_spec->num += ft_putchar_len(' ', str_spec->width * (-1) - len - 1);
		str_spec->num += ft_putchar_len('-', 1);
		str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		str_spec->num += ft_putnbr(i * -1, str_spec);
		str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
	}
	else if (i == 0)
		str_spec->num += ft_putchar_len(' ', str_spec->width - len);			
}

void		return_i(t_flags *str_spec, int i)
{
	int len;

	len = ft_digit_strlen(i);
	if (i < 0)
	{
		if (str_spec->tochnost > len) // (str_spec->tochnost > len 
		{
			//str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost - 1);
			str_spec->num += ft_putchar_len('-', 1);
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			str_spec->num += ft_putnbr(i * -1, str_spec);
		}
		else // str_spec->tochnost < len 
		{		
			if (!str_spec->zero)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);		
				str_spec->num += ft_putchar_len('-', 1);
			}	
			if (str_spec->zero)
			{		
				//str_spec->num += ft_putchar_len('0', str_spec->width - len - 1);	
				// if (i < 0)
				// 	i = i * -1;	
				str_spec->num += ft_putnbr(i , str_spec); // ?	
				str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);	
			}
			if (i < 0 && str_spec->width < 0)		
				str_spec->num += ft_putchar_len(' ', str_spec->width * (-1) - len - 1);
		}
	}
	else // число >= 0
	{
		if (str_spec->tochnost > len)
		{
			str_spec->num += ft_putchar_len('0',  str_spec->tochnost - len );
			if (i != 0)
				str_spec->num += ft_putnbr(i, str_spec);
			if (str_spec->width < 0)
			 	str_spec->num += ft_putchar_len(' ', str_spec->width * -1 - str_spec->tochnost);
		}
		else if (str_spec->tochnost != 0 && str_spec->tochnost < len)
		// else if (str_spec->tochnost < len && str_spec->mark_tochnost != -1) //&& (str_spec->width < 0 || !str_spec->zero) ) //-> 0
		{
			str_spec->num += ft_putnbr(i, str_spec); // 
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			if (str_spec->width < 0)
			{
				str_spec->width = str_spec->width * (-1);
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			}
		}
		else if (str_spec->zero && str_spec->width < 0)
		{
			str_spec->num += ft_putchar_len(' ',  str_spec->width * (-1) - len );
		}
	}
}

void		condition_2(t_flags *str_spec, int i)
{
	int len;
	
	len = ft_digit_strlen(i);
	if (!str_spec->tochnost) // == -1 -> не существует
    {
    	if (i < 0)
    	{
			if (str_spec->zero != 0) // существует
			{
				str_spec->num += ft_putchar_len('-', 1);
				str_spec->num += ft_putchar_len('0', str_spec->width - len);
				str_spec->num += ft_putnbr(i * (-1), str_spec);
			}
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			str_spec->num += ft_putnbr(i, str_spec);
		}
		else // число > 0
		{
			if (str_spec->zero && !str_spec->minus) // != 0 -> существует
			{
				str_spec->num += ft_putchar_len('0', str_spec->width - len);
				str_spec->num += ft_putnbr(i, str_spec);
			}
			else // if (str_spec->mark_tochnost != 2)// 0 нет 
			{	
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
				if (str_spec->mark_tochnost != 2 && i != 0)
					str_spec->num += ft_putnbr(i, str_spec);
			}
		}
		//return_i(str_spec, v1, i);
	}
	return_i(str_spec, i);
}

void		di_type(t_flags *str_spec, va_list v1)
{
	int		i;
	int		len;	
	// int		print_zero;

	// print_zero = 0;
	i = va_arg(v1, int);
	len = ft_digit_strlen(i);
	// if (str_spec->tochnost < 0)
	// 	str_spec->tochnost = str_spec->tochnost - 1;
	// print_zero = ft_putchar_len('0', str_spec->tochnost - len);

    if (str_spec->minus) // существует 
		condition_1(str_spec, i);
	else
		condition_2(str_spec, i);
}


	