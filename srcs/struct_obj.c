/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:15:55 by fmadura           #+#    #+#             */
/*   Updated: 2019/01/26 17:28:36 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_line	*obj_init(t_env *env, t_line *previous)
{
	t_line	*line;

	line = previous->objs;
	if (!line)
		return (NULL);
	line->wdist = -1;
	line->sidew = previous->sidew;
	line->wdist = ldist(env, previous, previous->sidew == 0 ? 'x' : 'y');
	line->raydir.x = previous->raydir.x;
	line->raydir.y = previous->raydir.y;
	line->lineh = (int)(HEIGHT / line->wdist);
	line->start_draw = (-line->lineh / 2 + HEIGHT / env->hratio) + env->player.actions.is_up_down;
	line->start_draw < 0 ? line->start_draw = 0 : 0;
	line->end_draw = (line->lineh / 2.0 + (double)HEIGHT / env->hratio) + env->player.actions.is_up_down;
	line->end_draw >= HEIGHT ? line->end_draw = HEIGHT - 1 : 0;
	line->map.x = previous->map.x;
	line->map.y = previous->map.y;
	if (line->sidew == 0)
		line->wall.x = env->player.pos.y + line->wdist * previous->raydir.y;
	else
		line->wall.x = env->player.pos.x + line->wdist * previous->raydir.x;
	line->wall.x -= floor((line->wall.x));
	return (line);
}