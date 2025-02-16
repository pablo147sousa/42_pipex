/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:10:57 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/14 16:58:25 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(int ac, const char **av, t_pipex *pipex)
{
	// int		i;
	char	*line;

	if (ac <= 1)
		return (-1);
	// i = 1;
	line = "";
	pipex->out_fd = open(av[ac - 1], O_RDWR | O_CREAT, 0766);
	if (!ft_strcmp(av[1],"here_doc"))
	{
		pipex->in_fd = open(av[1], O_CREAT, 0766);
		if (pipex->in_fd < 0)
			return(perror("here_doc error"), -1);
		while (*line && !ft_strcmp(line, av[2]))
		{
			line = get_next_line_fd(pipex->in_fd, 0);
			free(line);
		}
	}
	return (1);
}

char	**ft_path(char *envp[])
{
	char	**matrix;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			temp = envp[i] + 5;
		i++;
	}
	matrix = ft_split((const char *) temp, ':');
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

t_pipex	*ft_init_struct(char *envp[], int size)
{
	t_pipex	*pipex;
	int		i;

	i = -1;
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (perror("struct malloc"), NULL);
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->is_invalid_infile = -1;
	pipex->cmd_count = 0;
	pipex->here_doc = -1;
	pipex->cmd_args = NULL;
	pipex->paths = ft_path(envp);
	if (!pipex->paths)
		return (free(pipex), perror("malloc paths"), NULL);
	pipex->cmd_args = malloc(sizeof(char **) * size);
	if (!pipex->cmd_args)
		return (free(pipex), perror("malloc args"), NULL);
	while (++i < size)
		pipex->cmd_args[i] = NULL;
	return (pipex);
}

char	*get_next_line_fd(int dst, int src)
{
	char	*line;

	if (dst < 0 || src < 0)
		return (perror("file error"), NULL);
	line = get_next_line(src);
	if (!line)
		return (perror("gnl error"), NULL);
	write(dst, line, ft_strlen(line));
	return (line);
}
