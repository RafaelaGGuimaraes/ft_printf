/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:03:24 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/11 19:38:56 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int n);

static int	ft_unumlen(unsigned int n);

// static void	*ft_calloc(size_t nmemb, size_t size);

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

// static void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void			*ptr;
// 	unsigned char	*zero;
// 	size_t			i;

// 	if (nmemb == 0 || size == 0)
// 		return (malloc(0));
// 	if (nmemb > (size_t) -1 / size)
// 		return (NULL);
// 	ptr = malloc(nmemb * size);
// 	if (!ptr)
// 		return (NULL);
// 	zero = (unsigned char *)ptr;
// 	i = 0;
// 	while (i < nmemb * size)
// 	{
// 		zero[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
