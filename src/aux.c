/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:46:10 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/25 11:33:48 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_pipex(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->paths)
		ft_clean_matrix(pipex->paths);
	if (pipex->cmd_args)
	{
		while (pipex->cmd_args[++i])
			ft_clean_matrix(pipex->cmd_args[i]);
		free(pipex->cmd_args);
	}
	if (pipex->childs)
		free(pipex->childs);
	if (pipex->out_fd > 0)
		close(pipex->out_fd);
	if (pipex->in_fd >= 0)
		close(pipex->in_fd);
	free(pipex);
}

void	ft_clean_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_dup(t_pipex *pipex, int count)
{
	int	status;

	if (count == pipex->cmd_count - 1)
	{
		status = dup2(pipex->out_fd, 1);
		if (status < 0)
			return (0);
	}
	else
	{
		status = dup2(pipex->pipe[1], 1);
		if (status < 0)
			return (0);
		close(pipex->pipe[1]);
	}
	close(pipex->out_fd);
	return (status);
}
