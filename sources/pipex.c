/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:42:50 by hamchur           #+#    #+#             */
/*   Updated: 2022/02/18 17:25:55 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(int *pipe_fd, char **argv, char **envp, int fd1)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(fd1, 0);
	dup2(pipe_fd[1], 1);
	cmd = ft_split(argv[2], ' ');
	path = find_path(envp);
	line = get_line(cmd[0], path);
	close(fd1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(line, cmd, envp);
}

void	child2(int *pipe_fd, char **argv, char **envp, int fd2)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(pipe_fd[0], 0);
	dup2(fd2, 1);
	cmd = ft_split(argv[3], ' ');
	path = find_path(envp);
	line = get_line(cmd[0], path);
	close(fd2);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	execve(line, cmd, envp);
}

void	pipex(char **argv, char **envp)
{
	int		fd1;
	int		fd2;
	pid_t	parent;
	int		pipe_fd[2];

	checking_fd(&fd1, &fd2, argv);
	if (pipe(pipe_fd) == -1)
		error_process();
	parent = fork();
	if (parent == -1)
		error_process();
	if (parent == 0)
		child1(pipe_fd, argv, envp, fd1);
	parent = fork();
	if (parent == -1)
		error_process();
	if (parent == 0)
		child2(pipe_fd, argv, envp, fd2);
	close(fd1);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(0);
	wait(0);
}

int	main(int argc, char **argv, char **envp)
{
	checking_args(argc);
	pipex(argv, envp);
	return (0);
}
