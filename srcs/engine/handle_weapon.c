/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:32:57 by fmadura           #+#    #+#             */
/*   Updated: 2019/04/13 16:46:45 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		handle_weapon(t_env *env)
{
	const t_wrap_wpn	*curr = env->player.inventory.current;
	t_actions			*actions;
	t_bloc				*bloc;

	actions = &env->player.actions;
	if (curr)
	{
		if (actions->is_loading)
		{
			actions->is_shooting = !actions->is_shooting;
			put_gun_load(env, env->time.frame);
			env->time.frame++;
		}
		else if (actions->is_shooting)
		{
			put_gun_shoot(env, env->time.frame);
			env->time.frame++;
		}
		else if (curr)
		{
			bloc = &env->world.armory[curr->current->ref].sprite;
			put_gun(env, bloc);
			env->time.frame = 0;
		}
	}
	return (0);
}
