/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/23 14:48:01 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/09/17 19:00:02 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

// Allocates memory (using malloc(3)) and returns a
// copy of ’s1’ with characters from ’set’ removed
// from the beginning and the end.

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*start;
// 		char	*end;
// 			char	*str;
// 				int		size;
// 					int		i;

// 						i = 0;
// 							while (s1[i] && ft_strchr((char *)set, s1[i]))
// 									i++;
// 										if (s1[i] == 0)
// 												return (ft_strdup(""));
// 													start = (char *)s1 + i;
// 														i = ft_strlen(s1) - 1;
// 															while (i >= 0 && s1[i] && ft_strchr((char *)set, s1[i]))
// 																	i--;
// 																		end = (char *)s1 + i;
// 																			size = end - start + 1;
// 																				str = (char *)malloc(sizeof(char) * (size + 1));
// 																					if (!str)
// 																							return (NULL);
// 																								str[0] = '\0';
// 																									ft_strlcpy(str, start, size + 1);
// 																										return (str);
// 																										}

// char *ft_strtrim(char const *s1, char const *set)
// {
// 	char	*start;
// 	char	*end;
// 	char	*str;
// 	int		size;
// 	int		i;

// 	if (!s1 || !set)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] && ft_strchr((char *)set, s1[i]))
// 		i++;
// 	if (s1[i] == 0)
// 		return (ft_strdup(""));
// 	start = (char *)s1 + i;
// 	i = ft_strlen(s1) - 1;
// 	while (i >= 0 && ft_strchr((char *)set, s1[i]))
// 		i--;
// 	end = (char *)s1 + i;
// 	size = end - start + 1;
// 	str = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, start, size + 1);
// 	return (str);
// }


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
