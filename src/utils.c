/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:10:57 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/04 16:25:31 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(int ac, const char **av, t_pipex *pipex)
{
	pipex->out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0766);
	if (pipex->out_fd < 0)
		return (perror("out_fd error"), 0);
	pipex->in_fd = open(av[1], O_RDONLY);
	if (pipex->in_fd < 0)
	{
		pipex->in_fd = open("/dev/null", O_RDONLY);
		return (perror(NULL), 1);
	}
	return (1);
}

/// @brief Function to get a matrix of the enviroment variable.
/// @param envp Enviroment.
/// @param target Enviroment variable determinated.
/// @param split Char to split into a matrix.
/// @return A matrix null terminated. Each string terminated by /
char	**ft_getenv(char **envp, char *target, char split)
{
	char	**matrix;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], target, ft_strlen(target)))
			temp = envp[i] + (ft_strlen(target) + 1);
		i++;
	}
	matrix = ft_split((const char *) temp, split);
	if (!matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		temp = matrix[i];
		matrix[i] = ft_strjoin(matrix[i], "/");
		free (temp);
		i++;
	}
	return (matrix);
}

t_pipex	*ft_init_struct(char *envp[], int size, char const **av)
{
	t_pipex	*pipex;
	int		i;

	i = -1;
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (ft_putstr_fd("Error on malloc of the struct\n", 2), NULL);
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->cmd_count = size - 1;
	pipex->here_doc = (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0);
	pipex->paths = ft_getenv(envp, "PATH", ':');
	pipex->envp = envp;
	pipex->cmd_args = malloc(sizeof(char **) * size);
	if (!pipex->cmd_args)
		return (free(pipex), perror("malloc args"), NULL);
	while (++i < size - 1)
		pipex->cmd_args[i] = ft_parse(av[i + 2], ' ');
	pipex->cmd_args[i] = NULL;
	pipex->childs = malloc(sizeof(int) * pipex->cmd_count);
	if (!pipex->childs)
		return (ft_clean_pipex(pipex), ft_putstr_fd("Error on \
		childs array\n", 2), NULL);
	return (pipex);
}

int	wait_childs(t_pipex *pipex, int ac)
{
	int	i;
	int	status;
	int	pid_temp;

	i = 0;
	pid_temp = pipex->childs[i];
	while (i < ac - 3)
	{
		waitpid(pipex->childs[i], &status, 0);
		if (WIFEXITED(status) && pid_temp < pipex->childs[i])
			status = WEXITSTATUS(status);
		i++;
	}
	return (status);
}
