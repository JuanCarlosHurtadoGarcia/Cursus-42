/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:14:18 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/27 17:51:32 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		return (EXIT_FAILURE);
	ft_pipex(env, argv);
	return (0);
}

void	ft_pipex(char **env, char **argv)
{
	int		fd[2];
	pid_t	parent;
	int		status;

	pipe(fd);
	parent = fork();
	if (parent < 0)
		perror("Fork cannot be done");
	else if (!parent)
		ft_child(fd, argv, env);
	else
	{
		parent = fork();
		if (parent < 0)
			perror("Fork cannot be done");
		else if (!parent)
			ft_parent(fd, argv, env);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(parent, &status, 0);
}

void	ft_child(int *fd, char **argv, char **env)
{
	int		fd_file_1;
	char	*path;
	char	**cmds;

	fd_file_1 = open(argv[1], O_RDONLY);
	if (fd_file_1 == -1)
		return (perror("Pipex:File descriptor cannot be open"));
	dup2(fd_file_1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd_file_1);
	cmds = ft_split(argv[2], ' ');
	path = ft_path_finder(ft_paths(env), cmds[0]);
	if (execve(path, cmds, env) == -1)
	{
		perror("Pipex: command not found");
		ft_free(cmds);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_parent(int *fd, char **argv, char **env)
{
	int		fd_file_2;
	char	*path;
	char	**cmds;

	fd_file_2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_file_2 == -1)
		return (perror("Pipex:File descriptor cannot be open"));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_file_2, STDOUT_FILENO);
	close(fd[1]);
	close(fd_file_2);
	cmds = ft_split(argv[3], ' ');
	path = ft_path_finder(ft_paths(env), cmds[0]);
	if (execve(path, cmds, env) == -1)
	{
		perror("Pipex: command not found");
		ft_free(cmds);
		free(path);
		exit(EXIT_FAILURE);
	}
}
