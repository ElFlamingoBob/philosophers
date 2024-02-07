/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:23:13 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:11 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	result(int i, const char *src, int sign)
{
	long		result_1;
	long int	buff;

	result_1 = 0;
	while (src[i] >= 48 && src[i] <= 57)
	{
		buff = result_1;
		if (buff > result_1 * 10 + (src[i] - 48))
			return (-(sign == 0));
		result_1 = result_1 * 10 + (src[i] - 48);
		i++;
	}
	if (sign == 1)
		result_1 = -result_1;
	return (result_1);
}

int	ft_atoi(const char *src)
{
	int		i;
	long	result_final;
	int		sign;

	i = 0;
	sign = 0;
	while (src[i] == 32 || (src[i] >= 9 && src[i] <= 13))
		i++;
	if (src[i] == 45)
	{
		sign = 1;
		i++;
	}
	if (src[i] == 43 && sign == 0)
		i++;
	if (src[i] == 43 && sign == 1)
		return (0);
	result_final = result(i, src, sign);
	return (result_final);
}
