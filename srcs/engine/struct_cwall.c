/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cwall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:37:09 by fmadura           #+#    #+#             */
/*   Updated: 2019/05/08 23:38:04 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_cwall(t_drawline l, t_env *env)
{
	t_raycast	*ctn;
	int			*pixels;
	SDL_Surface	*sprite;
	t_cwall		cwall;

	ctn = ((t_raycast *)l.container);
	pixels	= (int *)env->sdl.surface->pixels;
	sprite = ctn->sprite;
	cwall.height = l.to - l.from;
	cwall.iter = 0;
	l.from = clamp(l.from, 0, H - 1);
	l.to = clamp(l.to, 0, H - 1);
	if (l.from == l.to)
		pixels[l.from * W + ctn->x] = 0xffffffff;
	else if (ctn->x == ctn->x1 || ctn->x == ctn->x2)
	{
		cwall.iter = l.from + 1;
		while (cwall.iter < l.to)
		{
			pixels[cwall.iter * W + ctn->x] = 0xffffffff;
			cwall.iter++;
		}
	}
	else if (l.to > l.from)
	{
		cwall.p = ctn->p;
		pixels[l.from * W + ctn->x] = 0xffffffff;
		cwall.iter = l.from + 1;
		cwall.y = 0;
		cwall.scaley = (ctn->li_sector.ceil - ctn->li_sector.floor) / 20;
		cwall.d = ((cwall.p.y2a - cwall.p.y1a)) * ((ctn->x2 - ctn->x1) - (ctn->x - ctn->x1))
			/ (ctn->x2 - ctn->x1) - cwall.p.y2a;
		cwall.x = (ctn->li_texture.floor * ((ctn->x2 - ctn->x) * ctn->rot.v2.y)
			+ ctn->li_texture.ceil * ((ctn->x - ctn->x1) * ctn->rot.v1.y))
			/ ((ctn->x2 - ctn->x) * ctn->rot.v2.y + (ctn->x - ctn->x1) * ctn->rot.v1.y);
		if (cwall.p.y1a < 0 && l.from == 0)
		{
			cwall.height += cwall.d;
			cwall.y += cwall.d;
			while (cwall.iter < l.to)
			{
				cwall.pos = (cwall.y / cwall.height * cwall.scaley) * sprite->h;
				pixels[cwall.iter * W + ctn->x] = getpixel(sprite, cwall.x % sprite->w, cwall.pos % sprite->h);
				cwall.y++;
				cwall.iter++;
			}
		}
		else if (cwall.p.y2a < 0 && l.from == 0)
		{
			cwall.height += cwall.d;
			cwall.y += cwall.d;
			while (cwall.iter < l.to)
			{
				cwall.pos = (cwall.y / cwall.height * cwall.scaley) * sprite->h;
				pixels[cwall.iter * W + ctn->x] = getpixel(sprite, cwall.x % sprite->w, cwall.pos % sprite->h);
				cwall.y++;
				cwall.iter++;
			}
		}
		else
		{
			while (cwall.iter < l.to)
			{
				cwall.pos = (cwall.y / cwall.height * cwall.scaley) * sprite->h;
				pixels[cwall.iter * W + ctn->x] = getpixel(sprite, cwall.x % sprite->w, cwall.pos % sprite->h);
				cwall.y++;
				cwall.iter++;
			}
		}
		pixels[l.to * W + ctn->x] = 0xffffffff;
	}
}
