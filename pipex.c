/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/20 17:00:02 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
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
	if (pipex->childs)
		free(pipex->childs);
	if (pipex->out_fd > 0)
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

void	child(t_pipex *pipex, char **program, int count)
{
	char	*temp;
	int		i;

	i = 0;
	close(pipex->pipe[0]);
	if (count == pipex->cmd_count - 1)
		dup2(pipex->out_fd, 1);
	else
		dup2(pipex->pipe[1], 1);
	while (pipex->paths[i])
	{
		temp = ft_strjoin((const char *) pipex->paths[i] \
		, (const char *) program[0]);
		execve(temp, program, NULL);
		free(temp);
		i++;
	}
	perror("Command not found");
	ft_clean_pipex(pipex);
	exit(0);
}

void	parent(t_pipex *pipex, int count)
{
	int	pid;

	if (pipe(pipex->pipe) < 0)
		return (perror("pipe error"));
	pid = fork();
	pipex->childs[count] = pid;
	if (pid == 0)
	{
		close(pipex->pipe[0]);
		if (count == pipex->cmd_count - 1)
			dup2(pipex->out_fd, 1);
		else
			dup2(pipex->pipe[1], 1);
		child(pipex, pipex->cmd_args[count], count);
	}
	else
	{
		close(pipex->pipe[1]);
		dup2(pipex->pipe[0], 0);
	}
}

int	main(int ac, char const **av, char *envp[])
{
	int		i;
	t_pipex	*pipex;

	if (!envp || !*envp)
		return (ft_putstr_fd("Invalid path\n", 2), 1);
	if (ac != 5)
		return (ft_putstr_fd("Invalid input\n", 2), 0);
	pipex = ft_init_struct(envp, ac - 2, av);
	if (!pipex)
		return (ft_putstr_fd("Unable to generate a valid structure\n", 2), 1);
	if (!check_files(ac, av, pipex) || (pipex->out_fd < 0))
		return (ft_clean_pipex(pipex), 1);
	dup2(pipex->in_fd, 0);
	i = -1;
	while (++i < pipex->cmd_count)
		parent(pipex, i);
	wait_childs(pipex, ac);
	close(pipex->in_fd);
	ft_clean_pipex(pipex);
	return (0);
}
