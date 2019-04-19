/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:03:46 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/19 19:12:58 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	vertex_of_sector(t_vtx *vtx, t_sct *sct)
{
	t_w_vtx		*ptr;

	ptr = sct->w_vtx_start;
	while (ptr)
	{
		if (ptr->vtx == vtx)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int			draw_mode(t_env *env)
{
	const t_pos			m = env->data->mouse;
	const SDL_Event 	event = env->data->sdl.event;
	const SDL_Rect  	rect = (SDL_Rect){20, 100, 850, 680};

	if (ui_mouseenter(m.x, m.y, rect))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && !env->editor.sct_hover)
		{
			env->editor.vtx_size = 0;
			if (!env->editor.drawing)
			{
				env->editor.drawing = 1;
				create_sector(env);
			}
			if (!env->editor.vtx_hover)
			{
				create_vertex(env->mouse, env);
				create_w_vertex(env->vertex, env);
				return (1);
			}
			else if (env->sct_current->w_vtx_start
			&& env->editor.vtx_hover == w_vtx_lst_end(env->sct_current->w_vtx_start)->vtx)
			{
				env->sct_current->close = 1;
				env->sct_current->w_vtx_current = 0;
				env->sct_current = 0;
				env->editor.drawing = 0;
				return (1);
			}
			else if (!vertex_of_sector(
			env->editor.vtx_hover, env->sct_current))
			{
				create_w_vertex(env->editor.vtx_hover, env);
				return (1);
			}
		}
	}
	if (m.x || m.y)
	{
		if (env->sct_current)
		{
			env->editor.vtx_size = pythagore(
			env->sct_current->w_vtx_current->vtx->pos, env->mouse);
		}
		return (1);
	}
	return (0);
}
