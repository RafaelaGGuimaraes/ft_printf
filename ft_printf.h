/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-g <rgomes-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:18:38 by rgomes-g          #+#    #+#             */
/*   Updated: 2025/08/10 20:37:45 by rgomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, va_list args);
int		convert_hex(va_list args, char specifier);
int		print_char(va_list args);
int		print_str(va_list args);
int		handle_specifier(char specifier, va_list args);
int		convert_int(va_list args);
int		print_percent(void);
int		convert_ptr(va_list args);
int		convert_unsigned(va_list args);
size_t	ft_strlen(const char *s);

#endif 