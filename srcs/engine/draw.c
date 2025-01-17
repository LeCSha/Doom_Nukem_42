/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:50:20 by fmadura           #+#    #+#             */
/*   Updated: 2019/05/08 23:22:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_l_int		wonder_wall(t_raycast ctn, t_projec projct, int *ytop, int *ybottom)
{
	t_l_int		limits;
	t_l_int		coord;
	int			diff_abs;
	int			diff_curr;

	diff_abs = ctn.x2 - ctn.x1;
	diff_curr = ctn.x - ctn.x1;
	coord.ceil = diff_curr * (projct.y2a - projct.y1a)
		/ (diff_abs) + projct.y1a;
	coord.floor = diff_curr * (projct.y2b - projct.y1b)
		/ (diff_abs) + projct.y1b;
	limits.ceil = clamp(coord.ceil, *ytop, *ybottom);
	limits.floor = clamp(coord.floor, *ytop, *ybottom);
	return (limits);
}

void		render_wall(t_env *env, t_raycast ctn, int *ytop, int *ybottom)
{
	t_l_int		y_cur;
	t_l_int		y_nxt;
	int			equal;

	equal = ctn.x == ctn.x1 || ctn.x == ctn.x2;
	y_cur = wonder_wall(ctn, ctn.p, ytop, ybottom);
	render_floor((t_drawline){(void *)&ctn, y_cur.floor + 1, *ybottom,
		0x0000FF, 0x0000AA, 0x0000FF}, env);
	if (ctn.neighbor >= 0)
	{
		y_nxt = wonder_wall(ctn, ctn.n, ytop, ybottom);
		render_nfloor((t_drawline){(void *)&ctn, y_cur.ceil,
			y_nxt.ceil - 1, 0, equal ? 0 : 0xFF00FF, 0}, env);
		*ytop = (int)clamp(fmax(y_cur.ceil, y_nxt.ceil), *ytop, H - 1);
		render_nwall((t_drawline){(void *)&ctn, y_nxt.floor + 1,
			y_cur.floor, 0, equal ? 0 : 0xBB4EFF, 0}, env);
		*ybottom = (int)clamp(fmin(y_cur.floor, y_nxt.floor), 0, *ybottom);
	}
	else
	{
		render_cwall((t_drawline){(void *)&ctn, y_cur.ceil,
			y_cur.floor, 0, 0, 0}, env);
	}
}

int			render_perspective(t_env *env, t_raycast *ctn)
{
	t_edge		bot;
	t_edge		top;
	t_vtx		horizon;
	t_vtx		vanish;
	int			max;

	bot = (t_edge){(t_vtx){ctn->x1, 600}, (t_vtx){ctn->x2, 600}};
	max = ctn->p.y2b < ctn->p.y1b ? ctn->p.y2b : ctn->p.y1b;
	top = (t_edge){(t_vtx){ctn->x1, max}, (t_vtx){ctn->x2, max}};
	horizon = (t_vtx){0, max};
	vanish = (t_vtx){W / 2, H / 2 - max / 2};
	draw_perspective(env->sdl.surface, (t_square){top, bot}, horizon, vanish);
	return (1);
}

void		dfs(t_env *env)
{
	t_queue		queue;
	t_engine	*engine;

	engine = &env->engine;
	queue = engine->queue;
	ini_queue(&queue, engine->nsectors);
	SDL_memset(env->sdl.surface->pixels, 0,
		env->sdl.surface->h * env->sdl.surface->pitch);
	*queue.head = (t_item) {engine->player.sector, 0, W - 1};
	if (++queue.head == queue.queue + MAXQUEUE)
		queue.head = queue.queue;
	while (queue.head != queue.tail)
	{
		queue.now = *queue.tail;
		if (++queue.tail == queue.queue + MAXQUEUE)
			queue.tail = queue.queue;
		if (queue.renderedsectors[queue.now.sectorno] & 0x21)
			continue ;
		++queue.renderedsectors[queue.now.sectorno];
		queue.sect = &engine->sectors[queue.now.sectorno];
		render_sector(env, &queue);
		++queue.renderedsectors[queue.now.sectorno];
	}
}
