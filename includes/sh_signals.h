/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:35:00 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:35:02 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SIGNALS_H
# define SH_SIGNALS_H

# include "shell.h"
# include <signal.h>
# include <errno.h>

int		g_signal;

void	sh_catch_signals(void);
void	sh_dfl_sig(void);

#endif
