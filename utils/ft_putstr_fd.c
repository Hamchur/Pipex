/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:13:56 by hamchur           #+#    #+#             */
/*   Updated: 2022/01/28 16:14:00 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd((char)s[i], fd);
		i++;
	}
}
