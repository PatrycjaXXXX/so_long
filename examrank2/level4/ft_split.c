/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:54:08 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/18 06:04:23 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int is_last_letter_in_word(char *s)
{
	return ((*(s+1) && ft_iswhitespace(*(s+1)))
		|| !*(s+1));
}

static int count_words(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]) && is_last_letter_in_word(str + i))
			count++;
		i++;
	}
	return (count);
}

static int count_word_len(char *str)
{
	int i = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
		i++;
	return (i);
}

void	ft_free_tab(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}

char **ft_split(char *str)
{
	int count_of_words = count_words(str);
	char **splited = malloc(sizeof(char *) * (count_of_words + 1));
	if (!splited)
		return (NULL);
	int word_len;
	int i = 0;
	int j = 0;
	int k;
	while (i < count_of_words)
	{
		while (str[j] && ft_iswhitespace(str[j]))
			j++;
		word_len = count_word_len(str + j);
		splited[i] = malloc(sizeof(char) * (word_len + 1));
		if (!splited[i])
		{
			splited[i] = NULL;
			ft_free_tab(splited);
			return (NULL);
		}
		k = 0;
		while (str[j] && !ft_iswhitespace(str[j]))
		{
			splited[i][k] = str[j];
			k++;
			j++;
		}
		splited[i][k] = '\0';
		i++;
	}
	splited[i] = NULL;
	return (splited);
}


int main()
{
	char *str = "some words   k   ";
	char **splited = ft_split(str);

	int	i;

	i = 0;
	while (splited[i])
		printf("%s\n", splited[i++]);
	ft_free_tab(splited);
	return 0;
}


