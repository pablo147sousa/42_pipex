/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/13 16:24:42 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "pipex.h"

void	child(char **path, char *program)
{
	char	**args;

	args = ft_split(program, 32);
	ft_exec(path, args);
}

void	parent(char **path, char **program, int ac)
{
	int	pid;
	int	i;

	i = 0;
	// pid = fork();
	if (pid == 0)
	{
		while (++i < (ac - 1))
		{
			fork();
			child(path, program[i]);
		}
	}	// wait(NULL);
	// else
	// {
	// }
}

void	ft_exec(char **path, char **program)
{
	char	*temp;
	int		i;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin((const char *) path[i],(const char *) program[0]);
		execve(temp, program, NULL);
		i++;
	}
	
}

int	main(int ac, char const **av, char *envp[])
{
	int		i;
	int		fds[2];
	char	**path;
	char	**args;

	if (ac < 0)
		return (0);
	fds[0] = ft_valid(ac, av);
	if (fds[0] < 0)
		return (1);
	i = -1;
	args = ft_split(av[1], 32);
	path = ft_path(envp);
	parent(path, (char **) av, ac);
	ft_clean_matrix(path);
	return (0);
}
