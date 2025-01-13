/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:30:43 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 11:28:21 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*var;

	i = 0;
	var = (char *)s;
	while (i < n)
	{
		var[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
