/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_f_engine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:41:58 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/08 23:01:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_F_ENGINE_H
# define DOOM_F_ENGINE_H

void		dfs(t_env *env);
int			is_crossing(const t_vtx p, t_vtx d, const t_vtx *vert, unsigned s);
int			is_bumping(const t_sector *sect, t_vision *vision,
			unsigned s, t_engine *e);

void		player_move(t_engine *e, t_vision *v, const Uint8 *keycodes);
void		handle_gravity(t_vision *v, t_engine *e, float gravity);
int			sector_collision(t_vtx player, t_vtx *dest, t_edge wall);
void		collision(t_vision *v, t_engine *e, t_sector *sect);

void		keyboard_movement(t_engine *engine, t_vision *v,
			const Uint8 *keycode);
int			sdl_mouse(t_engine *e, t_vision *v);
void		player_set(t_engine *e, t_vtx d);

int			sdl_set_velocity(t_env *env, t_vision *v, const Uint8 *keycodes);

t_edge		translation_edge(t_vctr player_position, t_vtx v1, t_vtx v2);
t_edge  	rotation_edge(t_edge v, float pcos, float psin);
t_edge 		scale_edge(t_edge to_scale);
void		clip_view(t_raycast *ctn);
int			ini_queue(t_queue *queue, unsigned size);
int     	verify_map(t_engine *engine);
int     	verify_hull(t_engine *engine);
void		print_sect(t_sector *sect);

void		vline(t_drawline line, t_env *env);
void		oline(t_drawline l, t_env *env, SDL_Surface *sprite);
void		render_cwall(t_drawline line, t_env *env);
void		render_nwall(t_drawline line, t_env *env);
void		render_floor(t_drawline line, t_env *env);
void		render_nfloor(t_drawline line, t_env *env);
void		render_ceil(t_drawline line, t_env *env);
void		render_nceil(t_drawline line, t_env *env);
void		render_sector(t_env *env, t_queue *queue);
void		render_wall(t_env *env, t_raycast ctn, int *ytop, int *ybot);
void		render_object(t_env *env, t_queue *queue);
void		render_enemies(t_env *env, t_queue *queue);
void		render_bullet(t_env *env, t_player p, t_impact *shot, t_queue *q);
void		render_sprites(t_env *env, SDL_Surface *s, t_vctr v, t_l_float si);
int			transform_vertex(t_raycast *ctn, t_player plr, t_vtx v1, t_vtx v2);

t_sector	*pick_sector(t_env *env, unsigned sector);
void		print_sct(t_env *env);
void		schedule_queue(t_queue *q, t_raycast container, int start, int end);

t_scaler	scaler_init(int a, int b, int c, int d, int f);
int			scaler_next(t_scaler *i);
t_vtx		screen_to_map(t_engine *e, float mapY, float screenX, float screenY);
t_vtx		relative_to_absolute(t_player player, float X, float Z);
void		acquire_limits(t_engine *e, t_raycast *ctn, t_l_float limit);

#endif
