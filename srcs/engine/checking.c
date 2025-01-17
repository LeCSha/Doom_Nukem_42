/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:47:46 by fmadura           #+#    #+#             */
/*   Updated: 2019/05/07 15:21:59 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	is_bumping(const t_sector *sect, t_vision *vision,
		unsigned s, t_engine *e)
{
	float	hole_low;
	float	hole_high;

	if (sect->neighbors[s] < 0)
		return (1);
	else
	{
		hole_low = fmax(sect->floor, e->sectors[sect->neighbors[s]].floor);
		hole_high = fmin(sect->ceil, e->sectors[sect->neighbors[s]].ceil);
	}
	return (hole_high < e->player.where.z + HEADMARGIN
		|| hole_low > e->player.where.z - vision->eyeheight + KNEEHEIGHT);
}

int	is_crossing(const t_vtx player, t_vtx dest,
		const t_vtx *vert, unsigned s)
{
	const t_vtx	add = add_vertex(player, dest);

	return (intersect_rect(player, add, vert[s], vert[s + 1])
			&& pointside(add, vert[s], vert[s + 1]) < 0.5);
}
