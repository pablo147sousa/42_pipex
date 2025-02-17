/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/17 16:36:23 by pmoreira         ###   ########.fr       */
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

// void	parent(char **path, char **program, int ac)
// {

// }

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

void	test(t_pipex *pipex)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(pipex->in_fd);
		if (!str)
			break;
		ft_printf("str = %s", str);
		free(str);
	}
}

int	main(int ac, char const **av, char *envp[])
{
	// char	*s;
	t_pipex	*pipex;

	if (ac != 5)
		return (0);
	pipex = ft_init_struct(envp, ac - 2);
	if (!pipex)
		return (perror("struct malloc"), 1);
	if (!check_files(ac, av, pipex))
		return (1);
	ft_printf("TEST:\n");
	test(pipex);
	if (!ft_strcmp(av[1],"here_doc"))
		unlink(av[1]);
	ft_clean_pipex(pipex);
	return (0);
}
