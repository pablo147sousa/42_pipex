/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:39 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/14 16:43:14 by pmoreira         ###   ########.fr       */
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

	str = "";
	while (str != NULL)
	{
		str = get_next_line(pipex->in_fd);
		if (str != NULL)
			printf("%s", str);
		free(str);
	}
}

int	main(int ac, char const **av, char *envp[])
{
	t_pipex	*pipex;

	if (ac != 5)
		return (0);
	pipex = ft_init_struct(envp, ac - 2);
	if (!pipex)
		return (perror("struct malloc"), 1);
	check_files(ac, av, pipex);
	test(pipex);
	ft_clean_pipex(pipex);
	return (0);
}
