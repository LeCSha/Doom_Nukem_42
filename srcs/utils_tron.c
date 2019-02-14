/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:46:58 by fmadura           #+#    #+#             */
/*   Updated: 2019/01/26 17:29:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

Uint32			line_tron_ceil(t_env *env, t_line *line, int y)
{
	t_point	fwall;
	double	weight;
	int		w;
	int		h;

	w = 512;
	h = 512;
	get_fwall(line, &fwall);
	weight = ((double)HEIGHT / (2.0 * y - HEIGHT)) / line->wdist;
	w = (int)((weight * fwall.x + (1.0 - weight) * env->player.pos.x) * w);
	h = (int)((weight * fwall.y + (1.0 - weight) * env->player.pos.y) * h);
	if (w % 512 < 5 || h % 512 < 5 || h % 512 > 507 || w % 512 > 507)
		return (0xFFc7ff00);
	return (0xff000000);
}

Uint32			line_tron_floor(t_env *env, t_line *line, int y)
{
	t_point	fwall;
	double	weight;
	int		w;
	int		h;

	w = 512;
	h = 512;
	get_fwall(line, &fwall);
	weight = ((double)HEIGHT / (2.0 * y - HEIGHT)) / line->wdist;
	w = (int)((weight * fwall.x - (1.0 + weight) * env->player.pos.x) * w);
	h = (int)((weight * fwall.y - (1.0 + weight) * env->player.pos.y) * h);
	w = w % 512;
	h = h % 512;
	return (0xff000000);
}

Uint32			line_tron_wall(t_env *env, t_line *line, int y)
{
	double		x;
	double		yy;
	double		delta;

	(void)env;
	x = (line->wall.x * 512);
	delta = 256 * (2.0 * y - (HEIGHT + line->lineh));
	yy = ft_abs(delta / line->lineh);
	if ((int)x % 512 < 5 || (int)yy % 512 < 5 || (int)x % 512 > 507 || (int)yy % 512 > 507)
		return (0xffc7ff00);
	return (0xff000000);
}

Uint32			line_tron_objs(t_env *env, t_line *line, int y)
{
	(void)env;
	(void)y;
	if (line->sidew == 0 && line->raydir.x > 0)
		return (0xFFff0000);
	else if (line->sidew == 0 && line->raydir.x < 0)
		return (0xFf11ff11);
	else if (line->sidew == 1 && line->raydir.y > 0)
		return (0xff1100ff);
	return (0xffc7ffaa);
}
