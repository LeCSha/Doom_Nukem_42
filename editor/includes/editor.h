/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:58:34 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/08 23:25:22 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# define C_BLACK 0xFF000000
# define C_WHITE 0xFFFFFFFF
# define C_RED 0xFF0000FF
# define C_GREEN 0xFF00FF00
# define C_BLUE 0xFFFF0000

# define C_GREY 0xFF8C8C8C

# define SCN_CODE_SPACE 44
# define SCN_CODE_KP_MIN 89
# define SCN_CODE_KP_MAX 98
# define SCN_CODE_ALPHA_MIN 4
# define SCN_CODE_ALPHA_MAX 29
# define SCN_CODE_BACK 42

# include <stdio.h>

# include "libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <dirent.h>
# include <math.h>

# include "libui_struct.h"
# include "editor_struct.h"
# include "libui.h"

void		msc_del(void **ap);
void		dir_del(void **ap);
void		wdw_del(void **ap);
void		rdr_del(void **ap);
void		srf_del(void **ap);
void		txr_del(void **ap);
void		crs_del(void **ap);
void		ttf_del(void **ap);

/*
**	init/
*/

void		init_env(t_env *env, t_data *data);

/*
**	create_delete/
*/

void		create_object(t_elem *element, t_env *env);
void		create_vertex(t_pos pos, t_env *env);
void		create_w_vertex(t_vtx *vtx, t_env *env);
void		insert_w_vertex(t_w_vtx *prev, t_vtx *vtx, t_env *env);
void		create_sector(t_env *env);
void		delete_object(t_object *obj, t_env *env);
void		delete_vertex(t_vtx *vtx, t_env *env);
int			delete_w_vertex(t_sct *sct, t_vtx *vtx);
void		delete_sector(t_sct *sector, t_env *env);
void		delete_edge(t_w_vtx *w_vtx, t_env *env);

/*
**	display/
*/

void		menu(t_env *env);
void		editor(t_env *env);
void		display_interface(t_env *env);
void		display_infos(t_env *env);
void		display_selection(t_env *env);
void		display_drawing(t_env *env);
void		display_element(t_env *env);
void		display_grid(t_env *env);

/*
**	events/
*/

void		click_sct_del(t_env *env);
void		click_edg_del(t_env *env);
void		click_vtx_del(t_env *env);
void		click_obj_del(t_env *env);
void		click_msc_music_btn(t_env *env);
void		click_msc_sbtx_btn(t_env *env);
void		click_msc_music(t_env *env);
void		click_msc_sbtx(t_env *env);
void		click_msc_miscup(t_env *env);
void		click_msc_miscdown(t_env *env);
void		click_edg_split(t_env *env);
void		click_sct_normal(t_env *env);
void		click_sct_door(t_env *env);
void		click_sct_fdoor(t_env *env);
void		click_sct_hceil(t_env *env);
void		click_sct_hfloor(t_env *env);
void		click_sct_gravity(t_env *env);
void		click_sct_ceil(t_env *env);
void		click_sct_sky(t_env *env);

int			menu_events(t_env *env);
int			handle_events(t_env *env);
int			draw_mode(t_env *env);
int			select_mode(t_env *env);
int			elem_mode(t_env *env);
int			move_mode(t_env *env);
t_vtx		*target_vertex(t_pos pos, t_env *env);
t_w_vtx		*target_edge(t_pos pos, t_env *env);
t_sct		*target_sector(t_pos pos, t_env *env);
t_object	*target_object(t_pos pos, t_env *env);

void		click_obj_del(t_env *env);
void		click_vtx_del(t_env *env);
void		click_sct_normal(t_env *env);
void		click_sct_door(t_env *env);
void		click_sct_fdoor(t_env *env);
void		click_sct_hceil(t_env *env);
void		click_sct_hfloor(t_env *env);
void		click_sct_gravity(t_env *env);
void		click_sct_ceil(t_env *env);
void		click_sct_sky(t_env *env);
void		click_sct_del(t_env *env);
void		click_edg_split(t_env *env);
void		click_edg_del(t_env *env);
void		click_msc_miscup(t_env *env);
void		click_msc_miscdown(t_env *env);
void		click_msc_music(t_env *env);
void		click_msc_sbtx(t_env *env);
void		click_msc_music_btn(t_env *env);
void		click_msc_sbtx_btn(t_env *env);

/*
**	export/
*/

void		export_map(t_env *env);
void		export_sectors(int fd, t_env *env);
void		export_objects(int fd, t_pos min, t_env *env);
void		export_vertex(int fd, t_pos min, t_env *env);

/*
**	utils/
*/

void		export_map(t_env *env);

float		pointside(t_pos p, t_pos p0, t_pos p1);
t_pos		get_edge_center(t_pos a, t_pos b);
float		pythagore(t_pos p1, t_pos p2);
int			point_in_rect(t_pos pos, SDL_Rect rect);

void		display_updown(int id_up, int id_down, t_env *env);
void		display_labeled_input(int id, char *str, t_env *env);
void		display_button(int id, char *str, t_env *env);
void		display_editor_dropdown_list(SDL_Rect rect, int dd, t_env *env);
void		display_error_msg(char *msg, t_env *env);

int			sector_in_rect(t_sct *sector, SDL_Rect rect, t_env *env);
t_elem		*get_element_by_ref(int ref, int dd, t_env *env);
int			shared_vtx(t_vtx *vtx, t_sct *current);
t_elem		*get_dd_element(int id, int dd, t_env *env);
int			refresh_object_sct(t_env *env);
t_pos		vtx_transform(t_pos pos, t_env *env);
t_w_vtx		*w_vtx_lst_end(t_w_vtx *lst);
t_sct		*sct_lst_end(t_sct *lst);
void		sync_sct_minmax(t_env *env);
int			input_add(int elem, char *key, t_env *env);
int			input_del(int elem, t_env *env);
int			ft_strchri(char *str, char c);
t_elem		*get_element(int id, t_env *env);
int			vertex_in_sector(t_sct *sector, t_pos pos);

#endif
