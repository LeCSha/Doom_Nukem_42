/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:41:49 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/07 17:30:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int		handle_w_vertex(t_vtx *vtx, t_env *env)
{
	t_sct		*sct_ptr;
	int			ret;

	ret = 1;
	sct_ptr = env->editor.sct_start;
	while (sct_ptr)
	{
		if (!(delete_w_vertex(sct_ptr, vtx)))
			ret = 0;
		sct_ptr = sct_ptr->next;
	}
	if (!ret)
		display_error_msg("Some w_vtx have not been deleted", env);
	return (ret);
}

void			delete_vertex(t_vtx *vtx, t_env *env)
{
	t_vtx	*ptr;
	t_vtx	*tmp;

	if (!handle_w_vertex(vtx, env))
		return ;
	ptr = env->editor.vertex;
	if (ptr == vtx)
	{
		env->editor.vertex = ptr->next;
		lt_release((void**)&ptr);
		env->nb_vtx--;
		return ;
	}
	while (ptr && ptr->next)
	{
		if (ptr->next == vtx)
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			lt_release((void**)&tmp);
			env->nb_vtx--;
		}
		ptr = ptr->next;
	}
}
