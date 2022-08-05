/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:39:42 by hamchur           #+#    #+#             */
/*   Updated: 2022/02/18 17:18:26 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);

void	error_file(char *file);
void	error_cmd(char *cmd);
void	error_process(void);
void	checking_args(int argc);
void	checking_fd(int *fd1, int *fd2, char **argv);

char	**find_path(char **envp);
char	*get_line(char *cmd, char **arr);

#endif
