/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_environment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:34:22 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:34:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENVIRONMENT_H
# define SH_ENVIRONMENT_H

char	**sh_envdup(char *env[]);
char	**sh_envvarsplit(char *value);
char	*sh_getenv(char *name, char *env[]);

#endif
