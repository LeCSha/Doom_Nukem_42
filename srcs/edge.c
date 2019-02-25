/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:44:58 by fmadura           #+#    #+#             */
/*   Updated: 2019/02/25 21:58:23 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** Build an edge with same rotation as the player
*/
t_edge  rotation_edge(t_player player, t_edge v)
{
	t_edge		edge;
	const float pcos = player.anglecos;
	const float psin = player.anglesin;
	
	edge.v1 = (t_vtx){
		v.v1.x * psin - v.v1.y * pcos,
		v.v1.x * pcos + v.v1.y * psin
	};
	edge.v2 = (t_vtx){
		v.v2.x * psin - v.v2.y * pcos,
		v.v2.x * pcos + v.v2.y * psin
	};
	return (edge);
}

/*
** Build an edge with current vectex and next vertex in sector
*/
t_edge  current_edge(t_vctr player_position, t_vtx v1, t_vtx v2)
{
	t_edge		edge;
	
	edge.v1 = (t_vtx){v1.x - player_position.x, v1.y - player_position.y};
	edge.v2 = (t_vtx){v2.x - player_position.x, v2.y - player_position.y};
	return (edge);
}

/*
** Build an edge with scale from perspective projection
*/
t_edge  scale_edge(t_edge t)
{
	t_edge		edge;
	
	edge.v1 = (t_vtx){
		hfov / t.v1.y,
		vfov / t.v1.y
	};
	edge.v2 = (t_vtx){
		hfov / t.v2.y,
		vfov / t.v2.y
	};
	return (edge);
}

/*
** If it's partially behind the player, clip it against player's view frustrum
*/
void	clip_view(t_edge *t)
{
	const t_vtx i1 = intersect_vtx(t->v1, t->v2,
		(t_vtx){-NEARSIDE, NEARZ}, (t_vtx){-FARSIDE, FARZ});
	const t_vtx i2 = intersect_vtx(t->v1, t->v2,
		(t_vtx){NEARSIDE, NEARZ}, (t_vtx){FARSIDE, FARZ});
	// Find an intersection between the wall and the approximate edges of player's view
	// t_vtx i1 = Intersect(t->x1,t->y1,t->x2,t->y2, -NEARSIDE,NEARZ, -FARSIDE,FARZ);
	// t_vtx i2 = Intersect(t->x1,t->y1,t->x2,t->y2, NEARSIDE,NEARZ, FARSIDE,FARZ);
	if (t->v1.y < NEARZ)
	{
		t->v1.x = (i1.y > 0) ? i1.x : i2.x;
		t->v1.y = (i1.y > 0) ? i1.y : i2.y;
	}
	if (t->v2.y < NEARZ)
	{
		t->v2.x = (i1.y > 0) ? i1.x : i2.x;
		t->v2.y = (i1.y > 0) ? i1.y : i2.y;
	}
}