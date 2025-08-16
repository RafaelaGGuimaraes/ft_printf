/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:37:58 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/15 21:38:00 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num);

static char	*int_to_hex(va_list args, char specifier);

int	convert_hex(va_list args, char specifier)
{
	char	*buffer;
	int		result;

	buffer = int_to_hex(args, specifier);
	if (!buffer)
		return (0);
	result = write(1, buffer, ft_strlen(buffer));
	free(buffer);
	return (result);
}

static char	*int_to_hex(va_list args, char specifier)
{
	char			*hex_digits;
	unsigned int	len;
	unsigned int	num;
	char			*buffer;

	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	num = va_arg(args, unsigned int);
	len = hex_len(num);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	while (len--)
	{
		buffer[len] = hex_digits[num % 16];
		num /= 16;
	}
	return (buffer);
}

static int	hex_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
