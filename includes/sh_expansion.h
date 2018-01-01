/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:34:29 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:34:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPANSION_H
# define SH_EXPANSION_H

t_token	*sh_expansion(t_token *lexer);
char	*sh_exp_tilde(char *lexeme);

#endif
