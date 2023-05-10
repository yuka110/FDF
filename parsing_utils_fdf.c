/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils_fdf.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 10:27:31 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/10 10:29:07 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	comma_check(char ***str)
{
	int		i;
	char	**s;
	char	*tmp;

	i = 0;
	s = *str;
	while (s[i])
	{
		if (locate_strchr(s[i], ','))
		{
			tmp = ft_substr(s[i], 0, locate_strchr(s[i], ','));
			free (s[i]);
			s[i] = tmp;
		}
		++i;
	}
}

int	locate_strchr(const char *s, int c)
{
	int	i;
	int	strlen;

	i = 1;
	strlen = ft_strlen(s);
	while (i - 1 < strlen && s)
	{
		if (s[i - 1] == c)
			return (i);
		++i;
	}
	return (0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}

void	ft_freet_point(t_point **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}