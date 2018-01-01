/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:33:54 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:34:00 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

int		sh_echo(char *av[]);
int		sh_cd(char *av[]);
int		sh_setenv(char *av[]);
int		sh_setenv_var(char *prg, char *var);
int		sh_unsetenv(char *av[]);
int		sh_env(char *av[], char *env[]);
int		sh_exit(char *av[], int ret);
int		sh_printenv(char *env[], char *var);
int		sh_hash(char *av[]);

int		sh_cd_opt(char *opt, char *str);
int		sh_concat_pwd(char **dir);
int		ft_access(char *dir, int mode, char *av);
int		sh_search_path(char **dir, char *av, int i);
int		sh_cd_exec2(char opt, char **dir, char **tab, char *av);

#endif
