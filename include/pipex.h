/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:11:31 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/24 11:28:56 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/include/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	int		pipe[2];
	int		cmd_count;
	int		*childs;
	char	**paths;
	char	***cmd_args;
}	t_pipex;

void	ft_exec(char **path, char **program);
void	child(t_pipex *pipex, char **program, int count);
void	parent(t_pipex *pipex, int count);

// UTILS

int		check_files(int ac, const char **av, t_pipex *pipex);
t_pipex	*ft_init_struct(char *envp[], int size, char const **av);
char	**ft_path(char *envp[]);
int		wait_childs(t_pipex *pipex, int ac);

// AUXS

int		ft_dup(t_pipex *pipex, int count);
void	ft_clean_matrix(char **matrix);
void	ft_clean_pipex(t_pipex *pipex);

#endif