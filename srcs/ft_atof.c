/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:56:52 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/16 22:00:18 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	process_fractional_part(const char *str)
{
	double	fractional_part;
	double	divisor;

	fractional_part = 0.0;
	divisor = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		divisor *= 10.0;
		fractional_part = fractional_part + (*str - '0') / divisor;
		str++;
	}
	return (fractional_part);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fractional_part;
	int		sign;

	result = 0.0;
	fractional_part = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		fractional_part = process_fractional_part(++str);
	return ((result + fractional_part) * sign);
}
