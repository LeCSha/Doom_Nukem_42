/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:25:14 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/29 18:13:01 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_STRUCT_H
# define EDITOR_STRUCT_H

enum					e_type
{
	INPUT,
	BUTTON,
	RECT
};

/*
** M_ : MENU
** E_ : EDITOR
** _I : INPUT
** _B : BUTTON
** _ELM_ : element page
** _SELEC_ : selection page
** _MISC_ : misc page
*/

enum					e_elements
{
	M_I_NEW,
	M_B_START,
	M_B_CANCEL,
	M_B_UP,
	M_B_DOWN,
	E_R_RECT,
	E_B_MENU,
	E_B_SAVE,
	E_B_MODE_SELECT,
	E_B_MODE_MOVE,
	E_B_MODE_DRAW,
	E_B_MODE_ELEM,
	E_B_PLAY,
	E_B_ELM_UP,
	E_B_ELM_DOWN,
	E_B_DRW_UP,
	E_B_DRW_DOWN,
	E_B_ELM_OBWL,
	E_B_ELM_CONS,
	E_B_ELM_NTTY,
	E_B_ELM_PRFB,
	E_B_ELM_SPEC,
	E_B_SELEC_DEL,
	E_I_SELEC_HCEIL,
	E_I_SELEC_HFLOOR,
	E_I_SELEC_GRAVITY,
	E_B_SELEC_SPLIT,
	E_B_SELEC_DOOR,
	E_B_SELEC_FDOOR,
	E_B_SELEC_CEIL,
	E_B_SELEC_SKY,
	E_B_SELEC_MUSIC,
	E_B_SELEC_SBTX
};

enum					e_obj_category
{
	WALL_OBJ,
	CONSUMABLE,
	ENTITY,
	PREFAB,
	SPECIAL
};

typedef struct	s_w_vtx		t_w_vtx;
typedef struct  s_vtx   	t_vtx;
typedef struct  s_sct   	t_sct;
typedef struct	s_elem		t_elem;
typedef struct	s_object	t_object;
typedef struct	s_menu		t_menu;
typedef struct	s_editor	t_editor;
typedef struct  s_env   	t_env;

struct					s_w_vtx
{
	int			fdoor;	// is final door
	int			door;	// is door

	int			ref;	// texture ref

	t_vtx		*vtx;
	t_sct		*sector;
	t_w_vtx		*next;
};

struct					s_vtx
{
	t_pos			pos;
	t_vtx			*next;
};

struct					s_sct
{
	int				id;			// identifiant du secteur

	int				nb_w_vtx;
	t_w_vtx			*w_vtx_current;	// vertex wrapper
	t_w_vtx			*w_vtx_start;	// vertex wrapper

	int				close;		// is sector close;

	int				roof;		// ceil or sky : 0 / 1
	int				ceil;		// hauteur ceil
	int				floor;		// hauteur floor
	int				gravity;

	float			xmin;
	float			xmax;
	float			ymin;
	float			ymax;

	Uint32			color;		// ?

	t_sct			*next;
};

struct					s_elem
{
	int				ref;
	int				id;
	int				type;
	SDL_Rect		rect;
	Uint32			color;
	SDL_Surface		*image;
	char			*str;		// if type == input
	int				str_max;	// if type == input

	int				clicked;
	int				hovered; // delete if not used ?

	t_elem			*next;
};

struct					s_object
{
	t_pos			pos;
	float			dir;	// if entity

	t_sct			*sct;
	int				ref;
	int				category;
	char			*name;

	Uint32			icon_color; // replace by image
	t_object		*next;
};

struct					s_menu
{
	int				state;

	// dropdown list
	int				nb_maps;
	int				idx_map;
	t_elem			*btn_maps;

	t_elem			*selected;		// upload selected
	SDL_Surface		*background;
};

struct					s_editor
{
	time_t			timestamp;	// error_msg timestamp
	char			*error_msg;

	int				obj_mode;	// 0/1/2/3/4 wall/cons/ntty/prfb/spe ??????????
	t_elem			*obj_elem;	// obj selectionne ??????????????

	// objects dropdown_lists
	int				nb_btn_wobj;
	int				nb_btn_cons;
	int				nb_btn_ntty;
	int				nb_btn_pref;
	int				nb_btn_spec;
	int				idx_btn_obj;
	t_elem			*btn_objs;

	// wall_textures dropdown_list
	int             nb_wall_txtr;
	int             idx_wall_txtr;
	t_elem			*wall_txtr;
	t_elem			*curr_wall_txtr;

	// skybox_textures dropdown_list
	int             nb_sb_txtr;
	int             idx_sb_txtr;
	t_elem			*sb_txtr;

	// background_audio dropdown_list
	int             nb_bg_audio;
	int             idx_bg_audio;
	t_elem			*bg_audio;

	// mouse handling
	int				mouse_mode;

	// drag vertex;
	int				mouse_drag;
	t_pos			new_pos;

	// grid move
	int				grid_drag;
	t_pos			grid_init_pos;
	t_pos			grid_mouse_var;
	t_pos			grid_translate;

	// hover / select
	t_vtx			*vtx_hover;
	t_w_vtx			*edg_hover;
	t_sct			*sct_hover;
	t_object		*obj_hover;

	t_vtx			*vtx_select;
	t_w_vtx			*edg_select;
	t_sct			*sct_select;
	t_object		*obj_select;

	// size current edge draw
	int				vtx_size;

	// state
	int				drawing;		// am i drawing an edge
};

struct					s_env
{
	t_data          *data;

	t_menu			menu;
	t_editor		editor;

	char			*map_name;

	// lst vertex
	t_vtx			*vertex;
	// lst sectors
	t_sct			*sct_current;
	t_sct			*sct_start;
	// lst objects
	t_object		*objects;
	// lst elements
	t_elem			*elements;	// ui elements

	// current elem / objects flags
	int				spawn_set;	// spawn pose, en attente de direction

	// variables
	float			grid_scale;

	// relative mouse_position
	t_pos			mouse;

	// data infos
	int				nb_vtx;
	int				nb_sct;
};

#endif
