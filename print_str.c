/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:36:52 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/15 21:36:54 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;
	size_t	len;

	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}
