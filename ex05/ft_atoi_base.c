/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:23:44 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/17 00:51:02 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_start(char *str, int *k)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*k *= -1;
		i++;
	}
	return (i);
}

int	ft_checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < 32 || str[i] > 126)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int ft_checkchar(char *str, char *base)
{
	int i;

	i = 0;
	


int	ft_index(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int blen;
	int nb;
	int k;

	nb = 0;
	blen = ft_checkbase(base);
	k = 0;
	if (ft_checkbase(base) == 0)
		return(0);
	i = ft_ft(str, &k);
	
	while (str[i] >= 32 && str[i] <= 126)
		{
			nb =  nb * blen + ft_index(str[i], base);
			i++;
		}
	return (nb * k);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", ft_atoi_base("ab", "abc"));
	return (0);
}
