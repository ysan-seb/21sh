/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:35:31 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 13:58:37 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
**	EXTERN LIB
*/

# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>
# include <pwd.h>
# include <dirent.h>
# include <termcap.h>
# include <time.h>

/*
**	DEFINE
*/

# define SHELL "21sh"
# define VERSION "1.0"
# define PATCH "0"

# define HIST_FILE ".21sh_history"
# define ERROR_MAX 5

# define PRT_SIZE 256
# define PATH_SIZE 2048
# define HASH_SIZE 10000
# define PROMPT_DIRTRIM 3
# define PS1B "\\s-\\v\\$ "
# define PS1 "\\e[1;38;5;202m\\u \\e[1;38;5;220m\\w \\$\\e[0m "
# define PS2 "> "
# define PS3 "#? "
# define PS4 "+ "

# define EOT 8
# define EOL 4
# define LEXER 2
# define DISP 1
# define DISP_FULL 17

# define SYN_ERR 4
# define LEX_LOOP 2
# define LEX_OK 1

# define UP 1
# define DOWN 2
# define RIGHT 4
# define LEFT 8
# define END 32
# define HOME 128
# define CTL 64

# define HIST_SEARCH 4

# define CASE(x) (x | 32)

# define RDR_SPEC 1
# define RDR_AMBG -2
# define RDR_BADFD -3
# define RDR_NOENT -4
# define RDR_NORGHT -5
# define RDR_PIPE -6

/*
**	RESSOURCES
*/

# include "../libft/includes/libft.h"
# include "sh_category.h"
# include "sh_struct.h"

/*
**	PROTO
*/

# include "sh_builtins.h"
# include "sh_color.h"
# include "sh_environment.h"
# include "sh_execution.h"
# include "sh_expansion.h"
# include "sh_hash.h"
# include "sh_hci.h"
# include "sh_initialization.h"
# include "sh_parser.h"
# include "sh_signals.h"
# include "sh_builtins.h"

#endif
