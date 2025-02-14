/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:11:31 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/14 16:34:59 by pmoreira         ###   ########.fr       */
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
	int		is_invalid_infile;
	int		cmd_count;
	char	**paths;
	char	***cmd_args;
}	t_pipex;

void	ft_exec(char **path, char **program);
void	child(char **path, char *program);
void	parent(char **path, char **program, int ac);

// UTILS

int		check_files(int ac, const char **av, t_pipex *pipex);
t_pipex	*ft_init_struct(char *envp[], int size);
char	**ft_path(char *envp[]);
char	*get_next_line_fd(int dst, int src);

// CLEANERS

void	ft_clean_matrix(char **matrix);
void	ft_clean_pipex(t_pipex *pipex);

#endif