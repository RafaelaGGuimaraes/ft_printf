/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:03:06 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/11 19:34:56 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long n);

static char	*hex_to_str(unsigned long num);

int	convert_ptr(va_list args)
{
	unsigned long	num;
	char			*buffer;
	int				result;

	num = (unsigned long)va_arg(args, void *);
	if (num == 0)
		return (write(1, "(nil)", 5));
	buffer = hex_to_str(num);
	if (!buffer)
		return (0);
	result = write(1, "0x", 2);
	result += write(1, buffer, ft_strlen(buffer));
	free(buffer);
	return (result);
}

static char	*hex_to_str(unsigned long num)
{
	char	*buffer;
	char	*hex_digits;
	int		len;

	hex_digits = "0123456789abcdef";
	len = ft_hexlen(num);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	while (len--)
	{
		buffer[len] = (hex_digits[num % 16]);
		num /= 16;
	}
	return (buffer);
}

static int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}
