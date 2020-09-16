/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:08:25 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/16 09:01:07 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int i;
	int k;
	int nb;

	i = 0;
	k = 1;
	nb = 0;
	while (ft_wspace(str[i]) == 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + str[i] - '0';
		i++;
	}
	return (nb * k);
}

#include <stdio.h>

int main()
{
	char str[]="  a   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
}
