/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:37:34 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/15 21:37:36 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count += parse_format(format, args);
	va_end(args);
	return (count);
}
