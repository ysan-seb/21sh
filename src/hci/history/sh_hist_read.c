/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hist_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:51:22 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:51:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*sh_hist_path(void)
{
	uid_t			uid;
	struct passwd	*home;

	uid = getuid();
	home = getpwuid(uid);
	return (home->pw_dir);
}

char	*sh_hist_line(char *line, char *gnl)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, gnl);
	ft_strdel(&gnl);
	if (tmp)
		ft_strdel(&tmp);
	if (!line)
		ft_error("Warning", "History not totally recoverded", NULL);
	if (line[ft_strlen(line) - (ft_strlen(line) ? 1 : 0)] == '\\')
		line[ft_strlen(line) - 1] = '\n';
	return (line);
}

t_line	*sh_hist_create(t_line *hist, char **line)
{
	t_line	*new;

	if (!(new = sh_hline_new(*line, hist)))
		ft_error("Warning", "History not totally recovered", NULL);
	ft_strdel(line);
	if (hist)
	{
		hist->down = new;
		hist = hist->down;
	}
	else
		hist = new;
	return (hist);
}

t_line	*sh_hist_gnl(int fd)
{
	t_line	*hist;
	char	*line;
	char	*gnl;
	int		ret;

	hist = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &gnl)) > 0)
	{
		if (!(line = sh_hist_line(line, gnl)))
			return (hist);
		if (line[ft_strlen(line) - (ft_strlen(line) ? 1 : 0)] != '\n')
		{
			if (!(hist = sh_hist_create(hist, &line)))
				return (hist);
		}
	}
	if (ret < 0)
		ft_error("Warning", "History not totally recovered", NULL);
	return (hist);
}

t_line	*sh_hist_read(void)
{
	t_line	*hist;
	t_line	*new;
	char	*path;
	int		fd;

	path = ft_strcjoin(sh_hist_path(), HIST_FILE, '/');
	fd = open(path ? path : HIST_FILE, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_strdel(&path);
	if (fd < 0)
		return (NULL);
	hist = sh_hist_gnl(fd);
	close(fd);
	if (!(new = sh_hline_new("", hist)))
		return (NULL);
	if (hist)
	{
		hist->down = new;
		hist = hist->down;
	}
	else
		hist = new;
	return (hist);
}
