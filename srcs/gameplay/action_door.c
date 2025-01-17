/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:07:36 by abaille           #+#    #+#             */
/*   Updated: 2019/05/08 16:49:05 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		door_neighbors(t_engine *e, t_vtx *v, int n)
{
	int			i;
	int			j;

	i = -1;
	while (++i < (int)e->nsectors)
	{
		j = -1;
		if (e->sectors[i].is_door)
		{
			while (++j < (int)e->sectors[i].npoints)
			{
				if (equal_vertex(v[n], e->sectors[i].vertex[j]))
				{
					j = -1;
					while (++j < (int)e->sectors[i].npoints)
					{
						if (equal_vertex(v[n + 1], e->sectors[i].vertex[j]))
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

int		select_door(t_engine *e)
{
	int			i;
	int			s;
	t_sector	*sect;

	i = -1;
	while (++i < (int)e->nsectors)
	{
		sect = &e->sectors[i];
		s = -1;
		if (sect->is_door)
		{
			while (++s < (int)sect->npoints)
			{
				if (dist_vertex((t_vtx){e->player.where.x, e->player.where.y},
				sect->vertex[s]) < 5)
					return (i);
			}
		}
	}
	return (-1);
}

int		access_door(t_env *e)
{
	int			index;
	t_sector	*sector;

	if ((index = select_door(&e->engine)) > -1)
	{
		sector = &e->engine.sectors[index];
		e->sound.state.open = 1;
		if (sector->is_door == 1 || !e->stats.data[I_KTOGO])
		{
			e->sound.state.is_open = !sector->door.is_open ? 1 : 2;
			sector->door.is_opening = 1;
		}
		else
			e->sound.state.open = 2;
	}
	return (1);
}

void	print_infos_door(t_env *env, t_sector *sector)
{
	int			index;
	t_door		*front_player;
	t_vtx		pos;
	int			door;
	const char	*string[2] = {STR_DOOR_0, STR_DOOR_1};

	if ((index = select_door(&env->engine)) > -1)
	{
		door = sector[index].is_door;
		pos = (t_vtx){W / 2, H / 2};
		front_player = &sector[index].door;
		if ((door == 1 || (!env->stats.data[I_KTOGO] && door == 2))
				&& !front_player->is_open && !front_player->is_opening)
			put_data(env, (t_font){
				WHITE, string[0], env->hud.font.text, pos, W / 40, -1, -1});
		else if (door == 2)
			put_data(env, (t_font){
				WHITE, string[1], env->hud.font.text, pos, W / 40, -1, -1});
	}
}

void	handle_doors(t_env *env)
{
	t_sector	*sector;
	int			i;

	i = -1;
	sector = env->engine.sectors;
	while (++i < (int)env->engine.nsectors)
	{
		if (sector[i].is_door)
		{
			if (sector[i].door.is_opening
			&& !sector[i].door.is_open && sector[i].ceil < 40)
				sector[i].ceil = (int)(sector[i].ceil + 1) % 41;
			else if (sector[i].door.is_open
			&& sector[i].door.is_opening && sector[i].ceil > 0)
				sector[i].ceil = (int)(sector[i].ceil - 1) % 41;
			else if ((sector[i].ceil >= 40 || sector[i].ceil <= 0)
			&& sector[i].door.is_opening)
			{
				sector[i].door.is_open = !sector[i].door.is_open;
				sector[i].door.is_opening = 0;
				(sector[i].is_door == 2) ? env->finish = 1 : 0;
			}
		}
	}
	print_infos_door(env, sector);
}
