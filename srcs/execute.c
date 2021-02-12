/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:46:10 by ahallain          #+#    #+#             */
/*   Updated: 2021/02/12 15:45:01 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include "../utils/lib.h"
#include "../utils/env.h"

int	execute_file(char *folder, char *file, char **args, char **env)
{
	char	*temp;
	pid_t	pid;
	int		status;

	if (!(temp = malloc(sizeof(char *))))
		return (-1);
	*temp = 0;
	ft_addstr(folder, &temp);
	ft_addstr("/", &temp);
	ft_addstr(file, &temp);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		execve(temp, args, env);
		exit(1);
	}
	waitpid(pid, &status, 0);
	free(temp);
	return (WEXITSTATUS(status));
}

int	execute(char **args, char **env)
{
	char			**folders;
	size_t			index;
	DIR				*dirp;
	struct dirent	*dp;
	int				ret;

	folders = ft_split(env_get(env, "PATH"), ':');
	ret = 256;
	index = 0;
	while (ret == 256 && folders[index])
	{
		if ((dirp = opendir(folders[index])) != NULL)
		{
			while ((dp = readdir(dirp)))
				if (ft_equals(*args, dp->d_name))
				{
					ret = execute_file(folders[index], dp->d_name, args, env);
					break ;
				}
			closedir(dirp);
		}
		index++;
	}
	index = 0;
	while (folders[index])
		free(folders[index++]);
	free(folders);
	return (ret);
}
