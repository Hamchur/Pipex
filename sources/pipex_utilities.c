/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:23:57 by hamchur           #+#    #+#             */
/*   Updated: 2022/02/18 18:01:41 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**find_path(char **envp)
{
	char	**arr;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			arr = ft_split(envp[i] + 5, ':');
			if (!arr)
				error_process();
			return (arr);
		}
		i++;
	}
	return (NULL);
}

char	*get_line(char *cmd, char **arr)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(line, X_OK) == 0)
			return (line);
		else
			free(line);
		i++;
	}
	error_cmd(cmd);
	return (NULL);
}
