/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:46:10 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/04 14:54:46 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_pipex(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->paths)
		ft_clean_matrix(pipex->paths);
	if (pipex->envp)
		pipex->envp = NULL;
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
	if (!matrix)
		return ;
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

void	try_run(t_pipex *pipex, char **program)
{
	if (program[0])
	{
		if (access(program[0], F_OK) == -1)
		{
			perror("Command not found");
			ft_clean_pipex(pipex);
			exit(127);
		}
		if (access(program[0], X_OK) == -1)
		{
			perror("Error");
			ft_clean_pipex(pipex);
			exit(126);
		}
		execve(program[0], program, pipex->envp);
	}
}
