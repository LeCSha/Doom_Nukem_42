/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:08:34 by fmadura           #+#    #+#             */
/*   Updated: 2019/02/25 22:19:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	acquire_limits(t_engine *e, t_queue *q, t_transf *ctn, int s)
{
	/* Check the edge type. neighbor=-1 means wall, 
	** other=boundary between two e->sectors. */
	ctn->neighbors = q->sect->neighbors[s];

	/* Acquire the floor and ceiling heights, 
	** relative to where the player's view is */
	ctn->lf_curr = (t_limit_float){q->sect->ceil - e->player.where.z,
		q->sect->floor - e->player.where.z};
	ctn->lf_next = (t_limit_float){0, 0};
	if (ctn->neighbors >= 0)
	{
		ctn->lf_next = (t_limit_float){
			e->sectors[ctn->neighbors].ceil - e->player.where.z,
			e->sectors[ctn->neighbors].floor - e->player.where.z
		};
	}
}

int		transform_vertex(t_engine *e, t_queue *q, t_transf *ctn, int s)
{
	/* Acquire the x,y coordinates of the two endpoints 
	** (vertices) of this edge of the sector */
	ctn->current = current_edge(e->player.where,
		q->sect->vertex[s], q->sect->vertex[s + 1]);

	/* Rotate them around the player's view */
	ctn->rot = rotation_edge(e->player, ctn->current);

	/* Is the wall at least partially in front of the player? */
	if (ctn->rot.v1.y <= 0 && ctn->rot.v2.y <= 0)
		return (0);

	/* If it's partially behind the player, 
	** clip it against player's view frustrum */
	if (ctn->rot.v1.y <= 0 || ctn->rot.v2.y <= 0)
		clip_view(&ctn->rot);

	/* Do perspective transformation */
	ctn->scale = scale_edge(ctn->rot);
	ctn->x1 = W/2 - (int)(ctn->rot.v1.x * ctn->scale.v1.x);
	ctn->x2 = W/2 - (int)(ctn->rot.v2.x * ctn->scale.v2.x);

	/* Verify if transformation is visible */
	if (ctn->x1 >= ctn->x2 || ctn->x2 < q->now.sx1 || ctn->x1 > q->now.sx2)
		return (0);
	acquire_limits(e, q, ctn, s);
	/* Project our ceiling & floor heights into screen coordinates (Y coordinate) */
	ctn->p = calc_projection(e->player.yaw, ctn->lf_curr, ctn->rot, ctn->scale);
	ctn->n = calc_projection(e->player.yaw, ctn->lf_next, ctn->rot, ctn->scale);
	return (1);
}