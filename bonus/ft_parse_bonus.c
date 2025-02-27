/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:23:53 by pmoreira          #+#    #+#             */
/*   Updated: 2025/02/27 16:17:40 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**ft_free(char **matrix, int index)
{
	while (index > 0)
		free(matrix[--index]);
	free(matrix);
	return (0);
}

static int	ft_add_word(char **matrix, const char *start, const char *end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (word == 0)
		return (0);
	while (start < end)
	{
		if (*start != '\'')
			word[i++] = *start;
		start++;
	}
	word[i] = '\0';
	*matrix = word;
	return (1);
}

static void	count_words(const char *s, int *words)
{
	int	quotes;
	int	valid;

	quotes = 0;
	valid = 0;
	while (*s)
	{
		if (*s == '\'')
			quotes = !quotes;
		if (*(s + 1) && *s == '\'' && *(s + 1) == '\'')
			*words += 1;
		else if (*s != ' ' || quotes)
		{
			if (!valid)
			{
				*words += 1;
				valid = 1;
			}
		}
		else if (*s == ' ' && !quotes)
			valid = 0;
		s++;
	}
}

static int	process_str(char **matrix, const char *s)
{
	int			quotes;
	int			index;
	const char	*start;

	index = 0;
	quotes = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		start = (char *)s;
		while (*s && (*s != ' ' || quotes))
		{
			if (*s == '\'')
				quotes = !quotes;
			s++;
		}
		if (s > start)
		{
			if (!ft_add_word(&matrix[index++], start, s))
				return (ft_free(matrix, index), 0);
		}
	}
	return (1);
}

char	**ft_parse(const char *s)
{
	char	**matrix;
	int		size;

	if (!s)
		return (NULL);
	size = 0;
	count_words(s, &size);
	if (size == 0)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (!matrix)
		return (NULL);
	matrix[size] = NULL;
	if (!process_str(matrix, s))
		return (ft_clean_matrix(matrix), NULL);
	return (matrix);
}
// #include <stdio.h>

// int main()
// {
// 	char	**matrix;
// 	char	*s = "cut -d ' ' -f 1";

// 	int i = -1;
// 	matrix = ft_parse(s);
// 	if (!matrix)
// 		return (printf("malloc\n"), 1);
// 	while(matrix[++i])
// 		printf("[%d]: %s\n", i, matrix[i]);
// 	return 0;
// }
