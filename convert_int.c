/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:02:46 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/11 19:42:56 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long int n);

static char	*ft_itoa(int n);

static void	*ft_calloc(size_t nmemb, size_t size);

int	convert_int(va_list args)
{
	char	*buffer;
	int		number;
	int		result;

	number = va_arg(args, int);
	buffer = ft_itoa(number);
	if (!buffer)
		return (0);
	result = write(1, buffer, ft_strlen(buffer));
	free(buffer);
	return (result);
}

static int	ft_numlen(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n)
{
	long int	nb;
	int			digits;
	char		*str;

	nb = n;
	digits = ft_numlen(nb);
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	while (digits > 0)
	{
		str[--digits] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*zero;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) -1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	zero = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		zero[i] = '\0';
		i++;
	}
	return (ptr);
}
