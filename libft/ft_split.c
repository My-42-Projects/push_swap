/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:26:31 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/08 14:10:57 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, int c)
{
	int	i;
	int	num_of_str;

	if (!s)
		return (0);
	i = 0;
	num_of_str = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num_of_str++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (num_of_str);
}

static void	ft_free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	*ft_get_next_substr(const char **s, char c)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*substr;

	start = *s;
	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	len = end - start;
	substr = ft_substr(start, 0, len);
	*s = end;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		i;
	int		num_of_str;

	num_of_str = ft_count(s, c);
	if (!num_of_str)
		return (NULL);
	str_arr = (char **)malloc((num_of_str + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (num_of_str > 0)
	{
		str_arr[i] = ft_get_next_substr(&s, c);
		if (!str_arr[i])
		{
			ft_free_split(str_arr);
			return (NULL);
		}
		i++;
		num_of_str--;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

/* static void	free_split(char **arr_of_str)
{
	int		i;

	i = 0;
	while (arr_of_str[i])
	{
		free(arr_of_str[i]);
		i++;
	}
	free(arr_of_str);
	exit(1);
}

static int	count_words(char *str, char separator)
{
	int		i;
	bool	is_inside_word;

	i = 0;
	while (*str)
	{
		is_inside_word = false;
		while (*str && *str == separator)
			str++;
		while (*str && *str != separator)
		{
			if (!is_inside_word)
			{
				i++;
				is_inside_word = true;
			}
			str++;
		}
	}
	return (i);
}

static char	*get_next_word(char *str, char separator)
{
	static int	index = 0;
	int			i;
	int			len;
	char		*next_str;

	i = 0;
	len = 0;
	while (str[index] == separator)
		index++;
	while (str[index + len] && (str[index + len] != separator))
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while (str[index] && (str[index] != separator))
		next_str[i++] = str[index++];
	next_str[i] = '\0';
	return (next_str);
}

char	**alt_split(char *s, char c)
{
	int		nbr_of_words;
	char	**arr_of_str;
	int		i;

	i = 0;
	nbr_of_words = count_words(s, c);
	if (nbr_of_words <= 1)
		exit(0);
	arr_of_str = malloc(sizeof(char *) * (size_t)(nbr_of_words + 2));
	if (!arr_of_str)
		return (NULL);
	while (nbr_of_words-- >= 0)
	{
		if (i == 0)
		{
			arr_of_str[i] = malloc(sizeof(char));
			if (arr_of_str[i] == NULL)
				free_split(arr_of_str);
			arr_of_str[i++][0] = '\0';
			continue ;
		}
		arr_of_str[i++] = get_next_word(s, c);
	}
	arr_of_str[i] = NULL;
	return (arr_of_str);
} */
