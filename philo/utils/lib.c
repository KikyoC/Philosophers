/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:18:18 by tom               #+#    #+#             */
/*   Updated: 2025/01/14 10:51:46 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	alloc_size(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		neg;
	long	nbr;

	nbr = (long)n;
	size = alloc_size(nbr);
	if (nbr < 0 || size == 0)
		size++;
	neg = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		neg++;
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (size-- > neg)
	{
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int		p;
	int		i;
	long	res;

	p = 1;
	i = 0;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			p = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	return ((int)(res * p));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] != '\0'
			|| (unsigned char)s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
