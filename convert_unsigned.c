/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:37:42 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/15 21:37:43 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int n);

static int	ft_unumlen(unsigned int n);

int	convert_unsigned(va_list args)
{
	char			*buffer;
	unsigned int	num;
	int				result;

	num = va_arg(args, unsigned int);
	buffer = ft_uitoa(num);
	if (!buffer)
		return (0);
	result = write(1, buffer, ft_strlen(buffer));
	free(buffer);
	return (result);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unumlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}
