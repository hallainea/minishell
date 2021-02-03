/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:10:31 by ahallain          #+#    #+#             */
/*   Updated: 2021/02/03 07:45:46 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_H
# define DEFAULT_H

int		prompt(char **env);
char	dispatch(char *content, char **env);
int		execute(char **args, char **env);
int		call_function(char **args, char **env);
char	**split_args(char *content, char **env);
void	sig();
#endif