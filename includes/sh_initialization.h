/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_initialization.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:35:07 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:35:08 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INITIALIZATION_H
# define SH_INITIALIZATION_H

int		sh_init(t_tc *init);
int		sh_init_env(void);
int		sh_init_termcaps(t_tc *init);
void	sh_init_loop(t_token **lexer, t_cmd ****list, int **op);

#endif
