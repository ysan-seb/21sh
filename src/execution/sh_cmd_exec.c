/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:37:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:37:15 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_exec_file(char *cmd, char **path)
{
	struct stat	buf;

	if (access(cmd, F_OK) < 0)
		return (ft_error(cmd, E_NOENT, NULL));
	if (stat(cmd, &buf) < 0)
		return (-1);
	if (S_ISDIR(buf.st_mode))
		return (ft_error(cmd, "Is a directory", NULL));
	if (access(cmd, X_OK) < 0)
		return (ft_error(cmd, "Permission denied", NULL));
	if (!(*path = ft_strdup(cmd)))
		return (-1);
	return (0);
}

static int	sh_exec_dir(char *cmd, char *dir)
{
	DIR				*dirp;
	struct dirent	*entry;
	int				ret;

	ret = 0;
	if ((dirp = opendir(dir)))
	{
		while ((entry = readdir(dirp)))
			if (ft_strequ(entry->d_name, cmd))
				ret = 1;
		closedir(dirp);
	}
	return (ret);
}

int			sh_exec_bin(char *cmd, char **path)
{
	char	**env_path;
	char	*p;
	size_t	i;
	int		found;

	if (ft_strequ(cmd, cmd[0] && cmd[1] ? ".." : ".") || !(p = getenv("PATH")))
		return (ft_error(cmd, E_NOCMD, NULL));
	if (!(env_path = sh_envvarsplit(p)))
		return (-1);
	i = 0;
	found = 0;
	while (env_path[i + 1] && !found)
		if (sh_exec_dir(cmd, env_path[i++]))
			found = 1;
	if (found)
		*path = ft_strcjoin(env_path[i - 1], cmd, '/');
	ft_strtabdel(env_path);
	if (!found)
		return (ft_error(cmd, E_NOCMD, NULL));
	else if (!*path)
		return (-1);
	if (access(*path, X_OK) < 0 && ft_error(cmd, "Permission denied", NULL))
		ft_strdel(path);
	return (*path ? 0 : 1);
}

static int	sh_father_child(pid_t child, char *path, char *av[], char *env[])
{
	int		ret;

	ret = 0;
	if (child == 0)
	{
		sh_dfl_sig();
		if (execve(path, av, env) < 0)
			exit(1);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(child, &ret, WUNTRACED);
		if (WIFSTOPPED(ret))
		{
			kill(child, SIGKILL);
			wait(&ret);
		}
		if (WIFSIGNALED(ret))
			write(1, "\n", 1);
	}
	return (WEXITSTATUS(ret));
}

int			sh_cmd_exec(char *av[], char *env[], char **path)
{
	pid_t		child;
	extern char	**environ;
	int			no_file;
	int			ret;

	ret = 0;
	if ((no_file = ft_strchr(av[0], '/') ?
				sh_exec_file(av[0], path) : sh_exec_bin(av[0], path)) < 0)
		return (-1);
	if (no_file)
		return (1);
	if ((child = fork()) < 0)
		return (-1);
	ret = sh_father_child(child, *path, av, env);
	sh_catch_signals();
	return (ret);
}
