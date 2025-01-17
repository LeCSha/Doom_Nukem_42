/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_s_engine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:41:58 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/08 23:38:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_S_ENGINE_H
# define DOOM_S_ENGINE_H

typedef struct	s_scaler	t_scaler;
typedef struct	s_sector	t_sector;
typedef struct	s_item		t_item;
typedef struct	s_engine	t_engine;
typedef struct	s_queue		t_queue;
typedef struct	s_raycast	t_raycast;
typedef struct	s_chain		t_chain;
typedef struct	s_door		t_door;
typedef struct	s_oline		t_oline;
typedef struct	s_cwall		t_cwall;


struct						s_door
{
	SDL_Surface				*sprite;
	int						is_openable;
	int						is_open;
	int						is_opening;
	int						ref_img;
	int						frame;
};

struct						s_scaler
{
	int		result;
	int		bop;
	int		fd;
	int		ca;
	int		cache;
};

struct						s_chain
{
	unsigned	a;
	unsigned	b;
	unsigned	c;
	unsigned	d;
	unsigned	e;
	unsigned	f;
	unsigned	g;
	unsigned	h;
};

struct						s_item
{
	int			sectorno;
	int			sx1;
	int			sx2;
};

struct						s_sector
{
	float		floor;
	float		ceil;
	t_vtx		*vertex;
	signed char	*neighbors;
	signed char	*textures;
	unsigned	npoints;
	int			is_door;
	int			has_skybox;
	int			gravity;
	int			type;
	t_door		door;
	t_wrap_sect	*head_object;
	t_wrap_enmy	*head_enemy;
};

struct						s_queue
{
	t_item		queue[MAXQUEUE];
	t_item		*head;
	t_item		*tail;
	t_item		now;
	t_sector	*sect;
	int			ytop[W];
	int			ybottom[W];
	int			*renderedsectors;
};

struct						s_raycast
{
	SDL_Surface		*sprite;
	t_edge			trsl;
	t_edge			rot;
	t_edge			scale;
	t_l_float		lf_current;
	t_l_float		lf_next;
	t_l_int			li_sector;
	t_l_int			li_texture;
	t_projec		p;
	t_projec		n;
	int				x;
	int				x1;
	int				x2;
	int				txtx;
	int				neighbor;
};

struct						s_engine
{
	t_sector		*sectors;
	unsigned		nsectors;
	unsigned		nvertex;
	t_player		player;
	t_queue			queue;
	t_minimap		minimap;
	int				keys[NB_OPT_KEY];
};

struct s_cwall
{
	int			iter;
	float		height;
	int			x;
	float		y;
	float		scaley;
	float		d;
	int			pos;
	t_projec	p;
};

struct						s_oline
{
	int				iter;
	int				x;
	float			y;
	float			height;
	float			width;
	Uint32			color;
};
#endif
