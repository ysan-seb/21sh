/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:41:46 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:41:48 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			main(void)
{
	t_tc	termcaps;
	t_token	*lexer;
	t_cmd	***cmd_list;
	int		*op;
	int		ret[2];

	if (sh_init(&termcaps))
		return (1);
	ret[0] = 0;
	ret[1] = ERROR_MAX;
	sh_catch_signals();
	while (ret[1])
	{
		sh_init_loop(&lexer, &cmd_list, &op);
		if (sh_hci(&termcaps, &lexer, ret[0]))
			ret[1] -= 1;
		else if (sh_parser(sh_expansion(lexer), &cmd_list, &op) < 0)
			ret[1] -= 1;
		else if ((ret[0] = sh_list_browse(cmd_list, op, ret[0])) < 0)
			ret[1] -= 1;
		lexer ? sh_token_del(&lexer) : 0;
		cmd_list ? sh_list_del(&cmd_list, &op) : 0;
	}
	ft_printf("\n\nToo many errors encountered, program has to quit.\n");
	return (1);
}
