/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/06 12:33:28 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pipex *pipex, char **program, int count)
{
	char	*temp;
	int		i;

	if (!program)
		return (ft_clean_pipex(pipex), exit(127));
	i = 0;
	close(pipex->pipe[0]);
	close(pipex->in_fd);
	ft_dup(pipex, count);
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
	exit(127);
}

void	parent(t_pipex *pipex, int count)
{
	int	pid;

	if (count != pipex->cmd_count - 1)
	{
		if (pipe(pipex->pipe) < 0)
			return (perror("pipe error"));
	}
	pid = fork();
	if (pid < 0)
		return (perror("PID error"));
	pipex->childs[count] = pid;
	if (pid == 0)
		child(pipex, pipex->cmd_args[count], count);
	else
	{
		close(pipex->pipe[1]);
		dup2(pipex->pipe[0], 0);
		close(pipex->pipe[0]);
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
	if (!check_files(ac, av, pipex))
		return (ft_clean_pipex(pipex), 1);
	dup2(pipex->in_fd, 0);
	close(pipex->in_fd);
	i = -1;
	while (++i < pipex->cmd_count)
		parent(pipex, i);
	close(0);
	i = wait_childs(pipex, ac);
	ft_clean_pipex(pipex);
	return (i);
}
