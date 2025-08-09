/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:04:24 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/09 19:07:28 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_specifier(char specifier, va_list args)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(args);
	else if (specifier == 's')
		printed = print_str(args);
	else if (specifier == 'd' || specifier == 'i')
		printed = convert_int(args);
	else if (specifier == 'x' || specifier == 'X')
		printed = convert_hex(args, specifier);
	else if (specifier == 'u')
		printed = convert_unsigned(args);
	else if (specifier == '%')
		printed = print_percent();
	else if (specifier == 'p')
		printed = convert_ptr(args);
	else
		write(1, "%", 1);
	return (printed);
}
