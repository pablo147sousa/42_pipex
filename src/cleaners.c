/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:40:11 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/19 09:53:32 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_pipex(t_pipex *pipex)
{
	int		i;

	i = -1;
	if (pipex->paths)
		ft_clean_matrix(pipex->paths);
	if (pipex->cmd_args)
	{
		while (pipex->cmd_args[++i])
			ft_clean_matrix(pipex->cmd_args[i]);
		free(pipex->cmd_args);
	}
	close(pipex->in_fd);
	close(pipex->out_fd);
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
