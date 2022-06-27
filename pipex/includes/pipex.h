/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:09:40 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/27 17:03:41 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_free(char **txt);
char	**ft_paths(char **env);
char	*ft_path_finder(char **paths, char *cmd);
void	ft_pipex(char **env, char **argv);
void	ft_child(int *fd, char **argv, char **env);
void	ft_parent(int *fd, char **argv, char **env);

#endif