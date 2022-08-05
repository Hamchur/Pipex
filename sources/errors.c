/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erorrs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:08:06 by hamchur           #+#    #+#             */
/*   Updated: 2022/02/18 16:41:24 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_file(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd("Error: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	checking_args(int argc)
{
	if (argc != 5)
	{	
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(0);
	}
}

void	error_process(void)
{
	perror("Error:  ");
	exit(1);
}

void	checking_fd(int *fd1, int *fd2, char **argv)
{
	*fd1 = open(argv[1], O_RDONLY);
	if (*fd1 == -1)
		error_file(argv[1]);
	*fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd2 == -1)
		error_file(argv[4]);
}
