/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:25:08 by fmadura           #+#    #+#             */
/*   Updated: 2019/01/25 15:09:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			sdl_exit_wolf(t_env *env)
{
		env_free(env);
		exit(0);
}

int			sdl_menu(t_env *env, Uint8 keycode)
{
	if (keycode == SDL_SCANCODE_ESCAPE)
	{
		SDL_FlushEvent(SDL_KEYDOWN | SDL_KEYUP);
		if (env->menu.is_active == 2)
		{
			env->menu.is_active = 0;
			env->menu.sub_menu = 0;
		}
		else if (env->menu.is_active == 1)
			env->menu.sub_menu = 0;
		else
		{
			env->menu.is_active = 2;
			env->menu.sub_menu = 2;
		}
		return (1);
	}
	return (0);
}

static int	sdl_check_pos(t_env *env, t_point mult, float check)
{
	int x;
	int y;

	x = env->player.pos.x + mult.x * check;
	y = env->player.pos.y;
	// Verify if pos not overstack map
	env->w_map[x][y] == 0 ? env->player.pos.x += mult.x * check : 0;
	x = env->player.pos.x;
	y = env->player.pos.y + mult.y * check;
	env->w_map[x][y] == 0 ? env->player.pos.y += mult.y * check : 0;
	return (1);
}

int			sdl_move(t_env *env, Uint8 *keycodes)
{
	if (keycodes[SDL_SCANCODE_W])
		sdl_check_pos(env, env->player.dir, 0.1);
	if (keycodes[SDL_SCANCODE_S])
		sdl_check_pos(env, env->player.dir, -0.1);
	if (keycodes[SDL_SCANCODE_D])
		sdl_check_pos(env, env->player.plane, 0.1);
	if (keycodes[SDL_SCANCODE_A])
		sdl_check_pos(env, env->player.plane, -0.1);
	return (0);
}

int			sdl_motion_mouse(t_env *env, int x, int y)
{
	double	mult;

	mult = -x / 4.0;
	env->player.dir = point_rotate(env->player.dir, mult);
	env->player.plane = point_rotate(env->player.plane, mult);
	env->player.angle_d += mult;
	env->player.angle_d > 358.0 ? env->player.angle_d = 0.0 : 0;
	env->player.angle_d < 0.0 ? env->player.angle_d = 358.0 : 0;
	env->player.actions.is_up_down += -y;
	return (0);
}

int			jumping(t_env *env, Uint8 keycode)
{
	if (keycode == SDL_SCANCODE_SPACE)
	{
		env->player.actions.is_jumping = 1;
		SDL_FlushEvent(SDL_KEYDOWN | SDL_KEYUP);
	}
	return (0);
}

int			sdl_keyhook(t_env *env, SDL_Event event)
{
	Uint8	keycode;
	Uint8	*keycodes;

	keycodes = (Uint8 *)SDL_GetKeyboardState(NULL);
	keycode = event.key.keysym.scancode;

	if (sdl_menu(env, keycode))
		return (0);
	if (env->menu.is_active)
	{
		if (keycodes[SDL_SCANCODE_DOWN] || keycodes[SDL_SCANCODE_UP])
		{
			move_button_menu(env, keycode);
			SDL_FlushEvent(SDL_KEYUP);
			SDL_FlushEvent(SDL_KEYDOWN);
			SDL_WaitEvent(&env->sdl.event);
		}
		else if (keycodes[SDL_SCANCODE_RETURN])
			select_button_menu(env, keycode);
		return (0);
	}
	sdl_move(env, (Uint8 *)keycodes);
	if (keycodes[SDL_SCANCODE_R])
		load_weapon(env, SDL_SCANCODE_R,
		env->player.inventory.weapons[0]->sprite_reload);
	if (keycodes[SDL_SCANCODE_SPACE])
		jumping(env, SDL_SCANCODE_SPACE);
	return (1);
}
