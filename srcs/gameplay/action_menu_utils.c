/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_menu_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:12:44 by abaille           #+#    #+#             */
/*   Updated: 2019/05/07 16:25:36 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	fill_levels(t_env *e, char *line, int fd)
{
	int	i;

	i = -1;
	while (++i < e->nb_levels)
	{
		e->levels[i] = ft_memalloc(sizeof(t_level));
		if ((get_next_line(fd, &line)) < 0)
			doom_error_exit("Doom_nukem: out of memory in load_world_data");
		e->levels[i]->index = ft_atoi(line);
		lt_release((void**)&line);
		if ((get_next_line(fd, &line)) < 0)
			doom_error_exit("Doom_nukem: out of memory in load_world_data");
		e->levels[i]->text = ft_strdup(line);
		lt_release((void**)&line);
	}
}

void	scroll_menu(t_env *e, int start, int limit, int which)
{
	const Uint8	*k = e->sdl.keycodes;
	t_status	*s;

	s = &e->menu.status;
	if (!which)
	{
		s->cur += k[SDL_SCANCODE_DOWN] ? 1 : 0;
		s->cur -= k[SDL_SCANCODE_UP] ? 1 : 0;
		s->cur < start ? s->cur = limit - 1 : 0;
		s->cur >= limit && (k[SDL_SCANCODE_DOWN] || k[SDL_SCANCODE_UP])
			? s->cur = start : 0;
	}
	else
	{
		if (k[SDL_SCANCODE_DOWN] && s->cur >= s->end && s->end < s->nb_save)
		{
			s->start++;
			s->end++;
		}
		if (k[SDL_SCANCODE_UP] && s->cur <= s->start && s->start > 1)
		{
			s->start--;
			s->end--;
		}
	}
}

int		check_doublon(t_status *s, int scan, int *ktab)
{
	int	i;

	i = 0;
	while (++i < NB_OPT_KEY)
	{
		if (ktab[i] == scan && i != s->cur)
		{
			s->key_change = 0;
			return (0);
		}
	}
	return (1);
}

void	change_option(t_env *e, t_status *s, const Uint8 *k, int *key)
{
	SDL_FlushEvents(SDL_QUIT, SDL_LASTEVENT);
	if (!k[SDL_SCANCODE_RETURN] && !k[SDL_SCANCODE_ESCAPE] && s->key_change)
	{
		SDL_WaitEvent(&e->sdl.event);
		if (s->cur == 0)
		{
			k[SDL_SCANCODE_LEFT] ? s->msc_vol-- : 0;
			k[SDL_SCANCODE_RIGHT] ? s->msc_vol++ : 0;
			s->msc_vol > MIX_MAX_VOLUME ? s->msc_vol = MIX_MAX_VOLUME : 0;
			s->msc_vol < 0 ? s->msc_vol = 0 : 0;
			Mix_VolumeMusic(e->menu.status.msc_vol);
		}
		else
		{
			(check_doublon(s, e->sdl.event.key.keysym.scancode, e->engine.keys))
			? *key = e->sdl.event.key.keysym.scancode : 0;
			s->key_change = 0;
		}
	}
	if (k[SDL_SCANCODE_RETURN] && !s->key_change && s->options_menu)
		s->key_change = 1;
	else if (k[SDL_SCANCODE_RETURN] && s->key_change && s->cur == 0)
		s->key_change = 0;
}

int		ispoint_inrect(int x, int y, SDL_Rect r)
{
	return (x >= r.x && x <= r.x + r.w && y >= r.y && y <= r.y + r.h);
}
