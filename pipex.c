/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/19 11:06:19 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "pipex.h"

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
	if (pid == 0)
		child(pipex, pipex->cmd_args[count], count);
	else
	{
		close(pipex->pipe[1]);
		wait(NULL);
		dup2(pipex->pipe[0], 0);
	}
}

int	main(int ac, char const **av, char *envp[])
{
	int		i;
	t_pipex	*pipex;

	if (ac < 4)
		return (0);
	pipex = ft_init_struct(envp, ac - 2, av);
	if (!pipex)
		return (perror("struct malloc"), 1);
	if (!check_files(ac, av, pipex))
		return (ft_clean_pipex(pipex), 1);
	dup2(pipex->in_fd, 0);
	i = -1;
	if (!ft_strcmp(av[1], "here_doc"))
		i++;
	while (++i < pipex->cmd_count)
		parent(pipex, i);
	if (!ft_strcmp(av[1], "here_doc"))
		unlink(av[1]);
	ft_clean_pipex(pipex);
	return (0);
}
