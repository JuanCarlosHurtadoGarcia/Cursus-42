/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:15:32 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/27 17:48:30 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(char **txt)
{
	int	i;

	i = -1;
	while (txt[++i])
		free(txt[i]);
	free(txt);
}

char	**ft_paths(char **env)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	path = NULL;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	tmp = &(env[i][5]);
	path = ft_split(tmp, ':');
	i = -1;
	while (path[++i])
		path[i] = ft_strjoin(path[i], "/");
	return (path);
}

char	*ft_path_finder(char **paths, char *cmd)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			ft_free(paths);
			close(fd);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
