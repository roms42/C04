/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:20:52 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/16 14:07:04 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int blen;
	
	i = 0;
	blen = ft_strlen(base);
	if (ft_checkbase(base) == 1)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		if (nbr < blen)
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base(nbr / blen, base);
			ft_putnbr_base(nbr % blen, base);
		}
	}
}


#include <stdio.h>

int main()
{
	char base[] = "0123456789abcdef";
	int n = -149405;
	printf("%d \n \n", ft_checkbase(base));
	ft_putnbr_base(n, base);
}
