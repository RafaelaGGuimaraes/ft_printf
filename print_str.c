/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:04:44 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/10 20:27:10 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;
	size_t	length;

	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	return (write(1, str, length));
}
