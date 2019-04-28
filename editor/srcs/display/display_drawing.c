/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:36:50 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/28 13:38:16 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void        display_drawing(t_env *env)
{
	SDL_Rect	rect;

	// display area rect
	rect = (SDL_Rect){890, 100, 290, 680};
	ui_make_rect(env->data->surface, rect, C_WHITE);

	// display title
	rect = (SDL_Rect){910, 110, 0, 20};
	ui_make_string(rect, "Wall texture", env->data);

	// up
	ui_make_rect(env->data->surface,
	get_element(E_B_DRW_UP, env)->rect, C_WHITE);
	// down
	ui_make_rect(env->data->surface,
	get_element(E_B_DRW_DOWN, env)->rect, C_WHITE);

	// display preview
	rect = (SDL_Rect){910, 150, 250, 150};
	ui_make_rect(env->data->surface, rect, C_WHITE);

	// display wall textures
	rect = (SDL_Rect){910, 320, 200, 400};
	display_dropdown_list(rect, env->editor.wall_txtr,
		env->editor.idx_wall_txtr, env);
}
