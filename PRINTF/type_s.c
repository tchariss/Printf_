/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:33 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 16:22:52 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s)); 
	return (0);
}

void		type_s(t_flags *str_spec, va_list v1)
{
	char	*s;
	s = va_arg(v1, char*);

	// if (!str_spec->tochnost) // то есть точность как была - так и осталась ( не найдена )
	// {	
	// 	str_spec->mark_tochnost = -1;
	// }
	// 1 условие
	if (str_spec->mark_tochnost == 2)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	if (str_spec->minus || str_spec->width < 0) // !str_spec->tochnost -> точности нет 
	{ 
		if (!str_spec->width || (str_spec->minus && !str_spec->width * (-1)) || 
		(str_spec->width < 0 && (str_spec->width * (-1)) < ft_strlen(s)) ||
		(str_spec->minus && str_spec->width < 0 && (str_spec->width * (-1)) < ft_strlen(s)) ||
		(str_spec->minus && str_spec->width && str_spec->tochnost == 0 && 
		str_spec->width > 0 && str_spec->mark_tochnost != 1 && str_spec->mark_tochnost != 2))
		{
			str_spec->num += write(1, s, ft_strlen(s));
		}
		if ((str_spec->width < 0 && (str_spec->width * (-1)) > ft_strlen(s)) ||
		(str_spec->minus && str_spec->width < 0 && (str_spec->width * (-1)) > ft_strlen(s)))
		{
			str_spec->num += write(1, s, ft_strlen(s));
			str_spec->num += ft_putchar_len(' ', (str_spec->width * (-1)) - ft_strlen(s));
		}
		else if (str_spec->minus && str_spec->width && str_spec->tochnost)
		{
			str_spec->num += write(1, s, str_spec->tochnost);
			str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
		}
		else if (str_spec->minus && str_spec->width && str_spec->mark_tochnost == 1) 
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
	}
	// 2 условие
	else if (str_spec->tochnost > 0 || str_spec->mark_tochnost == 1) // существует точность
	{
		if (str_spec->minus && str_spec->width && str_spec->mark_tochnost == 1) 
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		if (str_spec->width)
		{
			if (str_spec->tochnost < ft_strlen(s))
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
				str_spec->num += write(1, s, str_spec->tochnost);
			}
			else // точность > ft_strlen(s)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
				str_spec->num += write(1, s, ft_strlen(s));
			}
		}
		else
		{
			if (str_spec->tochnost < ft_strlen(s))
			{
				str_spec->num += write(1, s, str_spec->tochnost);
			}
			else // точность > ft_strlen(s)
			{
				str_spec->num += write(1, s, ft_strlen(s));
			}
			
		}
		
	}
	// else if (str_spec->minus && str_spec->width && str_spec->mark_tochnost == 2) 
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->width);
	// }
	// 3 условие
	else 
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
		str_spec->num += write(1, s, ft_strlen(s));
	}
	
}
// -------------------------- //
		// else
		// {
		// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
		// 	str_spec->num += write(1, s, ft_strlen(s));
		// }
// -------------------------- //
		



// //-----------------------------------------------------------------------------------//



	// if ((!str_spec->width && !str_spec->minus && !str_spec->tochnost) 
	// || (str_spec->tochnost > ft_strlen(s) && str_spec->tochnost > str_spec->width))
	// {
	// 	str_spec->num += write(1, s, ft_strlen(s));	
	// }
	// else if (str_spec->width < str_spec->tochnost && str_spec->width < ft_strlen(s))
	// {
	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// }
	// if (str_spec->width && str_spec->minus && str_spec->tochnost) 
	// {
	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// }	
	// // if (str_spec->width && str_spec->width < str_spec->tochnost && str_spec->width > ft_strlen(s))
	// // {
	// // 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// // 	str_spec->num += write(1, s, ft_strlen(s));
	
	// else if (str_spec->tochnost > ft_strlen(s) && str_spec->tochnost < str_spec->width)
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// 	str_spec->num += write(1, s, ft_strlen(s));
	// }
	// if (str_spec->width)
	// {
	// 	if (str_spec->width && str_spec->width < str_spec->tochnost && str_spec->width > ft_strlen(s))
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// }
	// if ((str_spec->width && str_spec->tochnost && str_spec->width > str_spec->tochnost && str_spec->width > ft_strlen(s)
	// && str_spec->tochnost < str_spec->width && str_spec->tochnost < ft_strlen(s))
	// || (str_spec->width > str_spec->tochnost && str_spec->width < ft_strlen(s)))
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// }

// //-----------------------------------------------------------------------------------//


	// if ((str_spec->width && str_spec->tochnost && str_spec->width > str_spec->tochnost && str_spec->width > ft_strlen(s)
	// && str_spec->tochnost < str_spec->width && str_spec->tochnost < ft_strlen(s))
	// || (str_spec->width > str_spec->tochnost && str_spec->width < ft_strlen(s)))
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// }

			// 	str_spec->num += write(1, s, ft_strlen(s));
		// if (str_spec->width > ft_strlen(s) && str_spec->width > str_spec->tochnost)
		// if (str_spec->width > ft_strlen(s) && str_spec->width < str_spec->tochnost)
		// {
		// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
		// 	str_spec->num += write(1, s, str_spec->tochnost);
		// }
		// if (str_spec->minus && str_spec->width < str_spec->tochnost && str_spec->width > ft_strlen(s)) 
		// {
		// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
		// 	str_spec->num += write(1, s, ft_strlen(s));
		// }
	
		// if (str_spec->width > ft_strlen(s))
		// {
		// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
		// 	str_spec->num += write(1, s, ft_strlen(s));
		// }


		//длина
			// if (str_spec->width > str_spec->tochnost && str_spec->tochnost > ft_strlen(s) && str_spec->width > ft_strlen(s))
			// {
			// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
			// 	str_spec->num += write(1, s, ft_strlen(s));
			// }
			
			// if (str_spec->width > str_spec->tochnost && str_spec->tochnost < ft_strlen(s) && str_spec->width > ft_strlen(s))
			// {
			// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
			// 	str_spec->num += write(1, s, ft_strlen(s));
			// }
			
			// if (str_spec->width > str_spec->tochnost)
			// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		if (ft_strlen(s) > str_spec->tochnost)
	// 		{
	// 			str_spec->num += ft_putstr(s, (str_spec->tochnost));
	// 			str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// 			//str_spec->num += ft_putstr(s, (str_spec->tochnost));
	// 		}
	// 		if (str_spec->tochnost > ft_strlen(s) && str_spec->width < ft_strlen(s))// просто печатаем строку 
	// 			str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// }
	// if (ft_strlen(s) > str_spec->tochnost && str_spec->tochnost != 0)
	// 	str_spec->num += ft_putstr(s, str_spec->tochnost);
	 // просто печатаем строку
	// else
	// 	str_spec->num += write(1, s, ft_strlen(s)); // если точности нет = 0
	
	// if (str_spec->minus == 0 && str_spec->tochnost == 0 && str_spec->width)
	// {
	// 	if (ft_strlen(s) > str_spec->tochnost)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 	}
	// 	str_spec->num += write(1, s, ft_strlen(s));
	// }
	
	// else if(!str_spec->tochnost && !str_spec->minus)
	// {
	// 	str_spec->num += write(1, s, ft_strlen(s));	
	// 	






// {
	// {
	// char	*s;

	// s = va_arg(v1, char*);
	// if (str_spec->width)
	// {	
	// 	// if (str_spec->width > ft_strlen(s))
	// 	// {
	// 	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 	// 	str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// 	if (str_spec->width < str_spec->tochnost) // (str_spec->tochnost > ft_strlen(s) && str_spec->width > str_spec->tochnost)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// 	if (str_spec->tochnost > ft_strlen(s) && str_spec->width > str_spec->tochnost)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// 	if (str_spec->minus && str_spec->width < str_spec->tochnost && str_spec->width < ft_strlen(s) && str_spec->tochnost > ft_strlen(s) && str_spec->tochnost < str_spec->width)
	// 	{
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 		//putstr(s, ft_strlen(s)) ? 
	// 	}
	// 	if (str_spec->tochnost && str_spec->minus) // && width 
	// 	{
	// 		str_spec->num += write(1, s, str_spec->tochnost);
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);	
	// 	}
	// 	if (str_spec->tochnost && str_spec->width > str_spec->tochnost && str_spec->tochnost < ft_strlen(s) && str_spec->tochnost < str_spec->width)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);	
	// 		str_spec->num += write(1, s, str_spec->tochnost);
	// 	}
	// 	if (str_spec->width > str_spec->tochnost && str_spec->width < ft_strlen(s))
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);	
	// 		str_spec->num += write(1, s, str_spec->tochnost);
	// 	}
	// 	// if (str_spec->tochnost && str_spec->minus)
	// 	// {
	// 	// 	str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);	
	// 	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// 	// }
	// 	if (str_spec->tochnost > ft_strlen(s) && str_spec->tochnost < str_spec->width)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// 	// if (str_spec->tochnost < ft_strlen(s) && str_spec->tochnost < str_spec->width)
	// 	// {
	// 	// 	str_spec->num += write(1, s, str_spec->tochnost);
	// 	// }
	// 		if (str_spec->width > ft_strlen(s))
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
	// 		str_spec->num += write(1, s, ft_strlen(s));
	// 	}
	// 	if (str_spec->tochnost && str_spec->minus)
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->tochnost);
	// }
	// }
	// if (str_spec->tochnost && str_spec->minus)
	// {
	// 	str_spec->num += ft_putchar_len(' ', str_spec->tochnost);
	// }
	// }
	// else
	// {
	// 	str_spec->num += write(1, s, ft_strlen(s));
	// }
	