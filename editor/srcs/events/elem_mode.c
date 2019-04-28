/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:14:41 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/28 13:42:18 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int			elem_mode(t_env *env)
{
	const SDL_Rect	rect = get_element(E_R_RECT, env)->rect;
	const t_pos		m = env->data->mouse;
	const int		tab[5] = {
	E_B_ELM_OBWL, E_B_ELM_CONS, E_B_ELM_NTTY, E_B_ELM_PRFB, E_B_ELM_SPEC};
	const SDL_Event event = env->data->sdl.event;
	//t_elem			*obj_btn;
	int				i;

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (ui_mouseenter(m.x, m.y, get_element(E_B_ELM_UP, env)->rect))
		{
			(env->editor.idx_btn_obj < 0) ? env->editor.idx_btn_obj++ : 0;
		}
		else if (ui_mouseenter(m.x, m.y, get_element(E_B_ELM_DOWN, env)->rect))
		{
			int nb = 0;
			if (env->editor.obj_mode == 0)
				nb = env->editor.nb_btn_wobj;
			else if (env->editor.obj_mode == 1)
				nb = env->editor.nb_btn_cons;
			else if (env->editor.obj_mode == 2)
				nb = env->editor.nb_btn_ntty;
			else if (env->editor.obj_mode == 3)
				nb = env->editor.nb_btn_pref;
			else if (env->editor.obj_mode == 4)
				nb = env->editor.nb_btn_spec;
			(env->editor.idx_btn_obj > -nb + 1) ? env->editor.idx_btn_obj-- : 0;
		}
		else if (ui_mouseenter(m.x, m.y, rect) && env->editor.obj_elem)
		{ // si click sur interface et object selectionne
			if (env->editor.sct_hover)
			{
				if (env->spawn_set == 1)
				{
					env->objects->dir = atan(
					(m.y - env->objects->pos.y) / (m.x - env->objects->pos.x));
					env->spawn_set = 0;
					return (1);
				}
				else if (env->editor.obj_elem->type == SPECIAL
					&& env->editor.obj_elem->id == 0)
				{ // if spawn
					env->spawn_set = 1;
				}
				create_object(env->editor.obj_elem, env);
			}
		}

		i = 0;
		while (i < 5)
		{
			if (ui_mouseenter(m.x, m.y, get_element(tab[i], env)->rect))
			{
				env->editor.idx_btn_obj = 0;
				env->editor.obj_mode = i;
				return (1);
			}
			i++;
		}

		// click on object button
		/*obj_btn = env->editor.btn_objs;
		while (obj_btn)
		{
			if (ui_mouseenter(m.x, m.y, obj_btn->rect)
			&& obj_btn->type == env->obj_mode)
				env->obj_elem = obj_btn;
			obj_btn = obj_btn->next;
		}*/
		return (1);
	}
	return (ui_mouseenter(m.x, m.y, rect) && (m.x || m.y));
}
