/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:34:48 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:34:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_HASH_H
# define SH_HASH_H

int			sh_hash_fct(char *cmd);
t_htable	*sh_hash_new(char *cmd, char *path);
t_htable	**sh_htable(void);
int			*sh_hindex(void);
int			sh_hash_set(char *cmd, char *path);
void		sh_hash_indapp(int new);
int			sh_hash_init(void);
char		*sh_hash_get(char *cmd);
void		sh_hash_disp(void);
void		sh_hash_free(void);

#endif
