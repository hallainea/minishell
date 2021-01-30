/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:07:43 by ahallain          #+#    #+#             */
/*   Updated: 2021/01/30 10:13:33 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils/lib.h"
#include "get_next_line/get_next_line.h"

void	prompt(char **env)
{
	char	*line;

	(void)env;
	while (1)
	{
		ft_putstr("$ ");
		get_next_line(2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
}