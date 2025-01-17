/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:15:13 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/08 23:36:30 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		display_object_data(t_object *obj, t_env *env)
{
	SDL_Rect		rect;

	rect = (SDL_Rect){910, 110, 250, 30};
	if (obj->dd == DD_WOBJ)
		ui_make_string(rect, "Wall_object", C_WHITE, env->data);
	else if (obj->dd == DD_CONS)
		ui_make_string(rect, "Consumable", C_WHITE, env->data);
	else if (obj->dd == DD_NTTY)
		ui_make_string(rect, "Entity", C_WHITE, env->data);
	else if (obj->dd == DD_PRFB)
		ui_make_string(rect, "Prefab", C_WHITE, env->data);
	else if (obj->dd == DD_SPEC)
		ui_make_string(rect, "Special", C_WHITE, env->data);
	rect = (SDL_Rect){910, 140, 250, 30};
	ui_make_string(rect, obj->name, C_WHITE, env->data);
	if (obj->sct)
		ui_make_nbrstring(rect, obj->sct->id, C_WHITE, env->data);
	else
		ui_make_string(rect, "No sector", C_WHITE, env->data);
	display_button(E_B_SELEC_OBJ_DEL, "DELETE", env);
}

static void		display_sector_data(char *str, t_env *env)
{
	SDL_Rect		rect;

	rect = (SDL_Rect){910, 110, 250, 30};
	ui_make_string(rect, str, C_WHITE, env->data);
	if (ft_strequ(str, "sector"))
	{
		rect = (SDL_Rect){1000, 110, 250, 30};
		ui_make_nbrstring(rect, env->editor.sct_select->id, C_WHITE, env->data);
		display_button(E_B_SELEC_NORMAL, "NORMAL", env);
		display_button(E_B_SELEC_DOOR, "DOOR", env);
		display_button(E_B_SELEC_FDOOR, "FINAL DOOR", env);
		display_labeled_input(E_I_SELEC_GRAVITY, "gravity", env);
		display_labeled_input(E_I_SELEC_HCEIL, "ceil height", env);
		display_labeled_input(E_I_SELEC_HFLOOR, "floor height", env);
		display_button(E_B_SELEC_CEIL, "CEIL", env);
		display_button(E_B_SELEC_SKY, "SKY", env);
		display_button(E_B_SELEC_SCT_DEL, "DELETE", env);
	}
	else if (ft_strequ(str, "edge"))
	{
		display_button(E_B_SELEC_SPLIT, "SPLIT", env);
		display_button(E_B_SELEC_EDG_DEL, "DELETE", env);
	}
	else if (ft_strequ(str, "vertex"))
		display_button(E_B_SELEC_VTX_DEL, "DELETE", env);
}

static void		display_misc_data(t_env *env)
{
	SDL_Rect		rect;

	rect = (SDL_Rect){910, 110, 250, 30};
	ui_make_string(rect, "Misc", C_WHITE, env->data);
	display_button(E_B_SELEC_MUSIC, "BACKGROUND MUSIC", env);
	display_button(E_B_SELEC_SBTX, "SKYBOX TEXTURE", env);
	rect = (SDL_Rect){910, 250, 200, 400};
	(get_element(E_B_SELEC_SBTX, env)->clicked)
	? display_editor_dropdown_list(rect, DD_SBTX, env)
	: display_editor_dropdown_list(rect, DD_BGAUDIO, env);
	display_updown(E_B_SELEC_MISC_UP, E_B_SELEC_MISC_DOWN, env);
}

void			display_selection(t_env *env)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){890, 100, 290, 680};
	ui_make_rect(env->data->surface, rect, C_WHITE);
	rect = (SDL_Rect){env->data->mouse.x, env->data->mouse.y - 40, 250, 30};
	if (env->editor.obj_hover)
		ui_make_string(rect, "object", C_WHITE, env->data);
	else if (env->editor.sct_hover)
		ui_make_string(rect, "sector", C_WHITE, env->data);
	else if (env->editor.vtx_hover)
		ui_make_string(rect, "vertex", C_WHITE, env->data);
	else if (env->editor.edg_hover)
		ui_make_string(rect, "edge", C_WHITE, env->data);
	if (env->editor.obj_select)
		display_object_data(env->editor.obj_select, env);
	else if (env->editor.sct_select)
		display_sector_data("sector", env);
	else if (env->editor.vtx_select)
		display_sector_data("vertex", env);
	else if (env->editor.edg_select)
		display_sector_data("edge", env);
	else
		display_misc_data(env);
}
