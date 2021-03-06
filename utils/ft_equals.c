/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:32:21 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/03 18:39:04 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	ft_equals(char *str1, char *str2)
{
	size_t	index;

	if (!str1 || !str2)
		return (false);
	index = 0;
	while (str1[index] && str1[index] == str2[index])
		index++;
	return (str1[index] == str2[index]);
}
