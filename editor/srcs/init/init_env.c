/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:24:28 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/29 20:25:36 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		create_element(int id, int type, SDL_Rect rect, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: Out of memory");
	new->id = id;
	new->type = type;
	new->rect = rect;
	new->color = C_WHITE;
	if (!(env->elements))
	{
		env->elements = new;
		env->elements->next = 0;
	}
	else
	{
		new->next = env->elements;
		env->elements = new;
	}
}

static void		create_btn_obj(int id, int ref, int type, char *str, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_obj, out of memory");
	new->id = id;
	new->ref = ref;
	new->type = type;
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_obj, out of memory");
	if (!(env->editor.btn_objs))
	{
		env->editor.btn_objs = new;
		env->editor.btn_objs->next = 0;
	}
	else
	{
		new->next = env->editor.btn_objs;
		env->editor.btn_objs = new;
	}
}

static void		create_btn_map(char *str, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_map, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_map, out of memory");
	if (!(env->menu.btn_maps))
	{
		env->menu.btn_maps = new;
		env->menu.btn_maps->next = 0;
	}
	else
	{
		new->next = env->menu.btn_maps;
		env->menu.btn_maps = new;
	}
}

static void		init_elems(t_env *env)
{
	SDL_Rect		rect;

	rect = (SDL_Rect){WIN_W / 2 - 390, WIN_H / 2 - 225 + 40, 300, 25};
	create_element(M_I_NEW, INPUT, rect, env);

	rect = (SDL_Rect){WIN_W / 2 - 400 + 410, WIN_H / 2 - 225 + 400, 150, 25};
	create_element(M_B_START, BUTTON, rect, env);

	rect = (SDL_Rect){WIN_W / 2 - 400 + 610, WIN_H / 2 - 225 + 400, 150, 25};
	create_element(M_B_CANCEL, BUTTON, rect, env);

	rect = (SDL_Rect){20, 20, 125, 40};
	create_element(E_B_MENU, BUTTON, rect, env);

	rect = (SDL_Rect){170, 20, 100, 40};
	create_element(E_B_SAVE, BUTTON, rect, env);

	rect = (SDL_Rect){20, 100, 850, 680};
	create_element(E_R_RECT, RECT, rect, env);

	rect = (SDL_Rect){WIN_W / 2 - 60, WIN_H / 2 + 5, 40, 40};
	create_element(M_B_UP, BUTTON, rect, env);
	get_element(M_B_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){WIN_W / 2 - 60, WIN_H / 2 + 55, 40, 40};
	create_element(M_B_DOWN, BUTTON, rect, env);
	get_element(M_B_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");

	rect = (SDL_Rect){600, 20, 50, 50};
	create_element(E_B_MODE_SELECT, BUTTON, rect, env);
	get_element(E_B_MODE_SELECT, env)->color = C_GREEN;
	get_element(E_B_MODE_SELECT, env)->image =
		ui_load_image("ressources/images/icons/cursor.png");

	rect = (SDL_Rect){650, 20, 50, 50};
	create_element(E_B_MODE_MOVE, BUTTON, rect, env);
	get_element(E_B_MODE_MOVE, env)->image =
		ui_load_image("ressources/images/icons/move.png");

	rect = (SDL_Rect){700, 20, 50, 50};
	create_element(E_B_MODE_DRAW, BUTTON, rect, env);
	get_element(E_B_MODE_DRAW, env)->image =
		ui_load_image("ressources/images/icons/line.png");

	rect = (SDL_Rect){750, 20, 50, 50};
	create_element(E_B_MODE_ELEM, BUTTON, rect, env);
	get_element(E_B_MODE_ELEM, env)->image =
		ui_load_image("ressources/images/icons/object.png");

	rect = (SDL_Rect){1030, 20, 150, 40};
	create_element(E_B_PLAY, BUTTON, rect, env);

	rect = (SDL_Rect){1130, 350, 20, 20};
	create_element(E_B_ELM_UP, BUTTON, rect, env);
	get_element(E_B_ELM_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){1130, 380, 20, 20};
	create_element(E_B_ELM_DOWN, BUTTON, rect, env);
	get_element(E_B_ELM_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");

	rect = (SDL_Rect){1130, 350, 20, 20};
	create_element(E_B_DRW_UP, BUTTON, rect, env);
	get_element(E_B_DRW_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){1130, 380, 20, 20};
	create_element(E_B_DRW_DOWN, BUTTON, rect, env);
	get_element(E_B_DRW_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");

	rect = (SDL_Rect){900, 110, 270, 20};
	create_element(E_B_ELM_OBWL, BUTTON, rect, env);
	get_element(E_B_ELM_OBWL, env)->clicked = 1;

	rect = (SDL_Rect){900, 140, 270, 20};
	create_element(E_B_ELM_CONS, BUTTON, rect, env);

	rect = (SDL_Rect){900, 170, 270, 20};
	create_element(E_B_ELM_NTTY, BUTTON, rect, env);

	rect = (SDL_Rect){900, 200, 270, 20};
	create_element(E_B_ELM_PRFB, BUTTON, rect, env);

	rect = (SDL_Rect){900, 230, 270, 20};
	create_element(E_B_ELM_SPEC, BUTTON, rect, env);

	rect = (SDL_Rect){910, 720, 250, 30};
	create_element(E_B_SELEC_DEL, BUTTON, rect, env);

	rect = (SDL_Rect){910, 250, 250, 30};
	create_element(E_I_SELEC_HCEIL, INPUT, rect, env);

	rect = (SDL_Rect){910, 320, 250, 30};
	create_element(E_I_SELEC_HFLOOR, INPUT, rect, env);

	rect = (SDL_Rect){910, 180, 250, 30};
	create_element(E_I_SELEC_GRAVITY, INPUT, rect, env);

	rect = (SDL_Rect){910, 250, 250, 30};
	create_element(E_B_SELEC_SPLIT, BUTTON, rect, env);

	rect = (SDL_Rect){910, 200, 250, 30};
	create_element(E_B_SELEC_DOOR, BUTTON, rect, env);

	rect = (SDL_Rect){910, 150, 250, 30};
	create_element(E_B_SELEC_FDOOR, BUTTON, rect, env);

	rect = (SDL_Rect){1130, 540, 20, 20};
	create_element(E_B_SELEC_M_WALL_UP, BUTTON, rect, env);
	get_element(E_B_SELEC_M_WALL_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){1130, 570, 20, 20};
	create_element(E_B_SELEC_M_WALL_DOWN, BUTTON, rect, env);
	get_element(E_B_SELEC_M_WALL_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");

	rect = (SDL_Rect){910, 370, 110, 30};
	create_element(E_B_SELEC_CEIL, BUTTON, rect, env);
	get_element(E_B_SELEC_CEIL, env)->color = C_GREEN;

	rect = (SDL_Rect){1040, 370, 120, 30};
	create_element(E_B_SELEC_SKY, BUTTON, rect, env);

	rect = (SDL_Rect){910, 420, 250, 30};
	create_element(E_B_SELEC_CEILTX, BUTTON, rect, env);
	get_element(E_B_SELEC_CEILTX, env)->clicked = 1;

	rect = (SDL_Rect){910, 460, 250, 30};
	create_element(E_B_SELEC_FLOORTX, BUTTON, rect, env);

	rect = (SDL_Rect){1130, 540, 20, 20};
	create_element(E_B_SELEC_TX_UP, BUTTON, rect, env);
	get_element(E_B_SELEC_TX_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){1130, 570, 20, 20};
	create_element(E_B_SELEC_TX_DOWN, BUTTON, rect, env);
	get_element(E_B_SELEC_TX_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");

	rect = (SDL_Rect){910, 150, 250, 25};
	create_element(E_B_SELEC_MUSIC, BUTTON, rect, env);
	get_element(E_B_SELEC_MUSIC, env)->clicked = 1;

	rect = (SDL_Rect){910, 190, 250, 25};
	create_element(E_B_SELEC_SBTX, BUTTON, rect, env);

	rect = (SDL_Rect){1130, 270, 20, 20};
	create_element(E_B_SELEC_MISC_UP, BUTTON, rect, env);
	get_element(E_B_SELEC_MISC_UP, env)->image =
		ui_load_image("ressources/images/icons/arrowup.png");

	rect = (SDL_Rect){1130, 300, 20, 20};
	create_element(E_B_SELEC_MISC_DOWN, BUTTON, rect, env);
	get_element(E_B_SELEC_MISC_DOWN, env)->image =
		ui_load_image("ressources/images/icons/arrowdown.png");
}

/*
**	Return nb of loaded objects
*/

static int		load_obj(char *path, int type, t_env *env)
{
	struct dirent       *de;
	DIR                 *dr;
	char				*name;
	int					ref;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir(path), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.' && ft_strchr(de->d_name, '+'))
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memeory in load_obj");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_btn_obj(i, ref, type, name, env);
			lt_release(name);
			i++;
		}
	}
	lt_release(dr);
	return (i);
}

/*
**	Return nb of loaded objects
*/

static int		load_specials(int type, t_env *env)
{
	create_btn_obj(0, 0, type, "Spawn", env);
	create_btn_obj(1, 0, type, "Interest", env);
	return (2);
}

static void		init_objs(t_env *env)
{
	env->editor.nb_btn_wobj =
		load_obj("ressources/objects/wall_objects", WALL_OBJ, env);
	env->editor.nb_btn_cons =
		load_obj("ressources/objects/consumables", CONSUMABLE, env);
	env->editor.nb_btn_ntty =
		load_obj("ressources/objects/entities", ENTITY, env);
	env->editor.nb_btn_spec = load_specials(SPECIAL, env);
}

static void		init_menu(t_env *env)
{
	struct dirent		*de;
	DIR					*dr;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir("maps/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open maps/");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			create_btn_map(de->d_name, env);
			env->menu.nb_maps++;
			i++;
		}
	}
	lt_release(dr);

	env->map_name = "new_map";
	env->menu.state = 1;
	env->menu.background = ui_load_image("ressources/images/doom-background.jpg");
}

static void     create_wall_txtr(char *str, int ref, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_obj, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_btn_obj, out of memory");
	new->ref = ref;
	if (!(env->editor.wall_txtr))
	{
		env->editor.wall_txtr = new;
		env->editor.wall_txtr->next = 0;
	}
	else
	{
		new->next = env->editor.wall_txtr;
		env->editor.wall_txtr = new;
	}
}

static void     create_sb_txtr(char *str, int ref, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_sb_txtr, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_sb_txtr, out of memory");
	new->ref = ref;
	if (!(env->editor.sb_txtr))
	{
		env->editor.sb_txtr = new;
		env->editor.sb_txtr->next = 0;
	}
	else
	{
		new->next = env->editor.sb_txtr;
		env->editor.sb_txtr = new;
	}
}

static void		load_skybox_txtr(t_env *env)
{
	char				*name;
	int					ref;
	struct dirent		*de;
	DIR					*dr;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir("ressources/skybox/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources/skybox");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memeory in init_editor");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_sb_txtr(name, ref, env);
			lt_release(name);
			env->editor.nb_sb_txtr++;
			i++;
		}
	}
	lt_release(dr);
}

static void     create_bg_audio(char *str, int ref, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_bg_audio, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_bg_audio, out of memory");
	new->ref = ref;
	if (!(env->editor.bg_audio))
	{
		env->editor.bg_audio = new;
		env->editor.bg_audio->next = 0;
	}
	else
	{
		new->next = env->editor.bg_audio;
		env->editor.bg_audio = new;
	}
}

static void		load_background_audio(t_env *env)
{
	char				*name;
	int					ref;
	struct dirent		*de;
	DIR					*dr;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir("ressources/audio/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources/audio/");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memory load_background_audio");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_bg_audio(name, ref, env);
			lt_release(name);
			env->editor.nb_bg_audio++;
			i++;
		}
	}
	lt_release(dr);
}

static void     create_ceil_txtr(char *str, int ref, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_ceil_txtr, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_ceil_txtr, out of memory");
	new->ref = ref;
	if (!(env->editor.ceil_txtr))
	{
		env->editor.ceil_txtr = new;
		env->editor.ceil_txtr->next = 0;
	}
	else
	{
		new->next = env->editor.ceil_txtr;
		env->editor.ceil_txtr = new;
	}
}

static void		load_ceil_txtr(t_env *env)
{
	char				*name;
	int					ref;
	struct dirent		*de;
	DIR					*dr;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir("ressources/images/ceil/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources/images/ceil/");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memory in laod_ceil_txtr");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_ceil_txtr(name, ref, env);
			lt_release(name);
			env->editor.nb_ceil_txtr++;
			i++;
		}
	}
	lt_release(dr);
}

static void     create_floor_txtr(char *str, int ref, t_env *env)
{
	t_elem   *new;

	if (!(new = lt_push(ft_memalloc(sizeof(t_elem)), ft_memdel)))
		ui_error_exit_sdl("Editor: create_floor_txtr, out of memory");
	if (!(new->str = lt_push(ft_strdup(str), ft_memdel)))
		ui_error_exit_sdl("Editor: create_floor_txtr, out of memory");
	new->ref = ref;
	if (!(env->editor.floor_txtr))
	{
		env->editor.floor_txtr = new;
		env->editor.floor_txtr->next = 0;
	}
	else
	{
		new->next = env->editor.floor_txtr;
		env->editor.floor_txtr = new;
	}
}

static void		load_floor_txtr(t_env *env)
{
	char				*name;
	int					ref;
	struct dirent		*de;
	DIR					*dr;
	int					i;

	i = 0;
	if (!(dr = lt_push(opendir("ressources/images/floor/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources/images/floor/");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memory in laod_floor_txtr");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_floor_txtr(name, ref, env);
			lt_release(name);
			env->editor.nb_floor_txtr++;
			i++;
		}
	}
	lt_release(dr);
}

static void		init_editor(t_env *env)
{
	char				*name;
	struct dirent		*de;
	DIR					*dr;
	int					i;
	int					ref;

	load_ceil_txtr(env);
	load_floor_txtr(env);
	load_skybox_txtr(env);
	load_background_audio(env);

	i = 0;
	if (!(dr = lt_push(opendir("ressources/images/wall/"), dir_del)))
		ui_error_exit_sdl("Editor: Unable to open ressources/images/wall/");
	while ((de = readdir(dr)))
	{
		if ((de->d_name)[0] != '.')
		{
			if (!(name = lt_push(ft_strsub(
					de->d_name, 0, ft_strchri(de->d_name, '+')), ft_memdel)))
				ui_error_exit_sdl("Editor: Out of memeory in init_editor");
			ref = ft_atoi(ft_strchr(de->d_name, '+'));
			create_wall_txtr(name, ref, env);
			lt_release(name);
			env->editor.nb_wall_txtr++;
			i++;
		}
	}
	lt_release(dr);

	// wall txtr par default
	if (!env->editor.curr_wall_txtr)
	{
		env->editor.curr_wall_txtr = env->editor.wall_txtr;
		env->editor.wall_txtr->clicked = 1;
	}

	env->grid_scale = 45;
	env->editor.grid_translate = (t_pos){0, 0};
}

void		init_env(t_env *env, t_data *data)
{
	ft_bzero(env, sizeof(t_env));
	env->data = data;
	init_elems(env);
	init_objs(env);
	init_menu(env);
	init_editor(env);
	ui_make_window("EDITOR", data);
	ui_load_font("ressources/fonts/Arial.ttf", data);
}
